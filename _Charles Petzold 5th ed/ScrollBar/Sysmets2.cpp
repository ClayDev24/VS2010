#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "sysmets.h"
#include "msgbox.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT("SysMets2");
     HWND         hwnd;
     MSG          msg;
     WNDCLASS     wc;

     wc.style         = CS_HREDRAW | CS_VREDRAW;
     wc.lpfnWndProc   = WndProc;
     wc.cbClsExtra    = 0;
     wc.cbWndExtra    = 0;
     wc.hInstance     = hInstance;
     wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
     wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
     wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
     wc.lpszMenuName  = NULL;
     wc.lpszClassName = szAppName;

     if(!RegisterClass(&wc))  
     {
          MessageBox(NULL, TEXT("This program requires Windows NT!"), 
                      szAppName, MB_ICONERROR);
          return 0 ;
     }
     hwnd = CreateWindow(szAppName, TEXT("Get System Metrics No. 2"),
                          WS_OVERLAPPEDWINDOW | WS_VSCROLL,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL);
     ShowWindow(hwnd, iCmdShow);
     UpdateWindow(hwnd);

     while(GetMessage(&msg, NULL, 0, 0))
     {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
     }
     return msg.wParam;
} // WinMain()

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     static int  cxChar, cxCaps, cyChar, cyClient, iVscrollPos;
	 int iVscrollMax;
     HDC         hdc;
     int         i, y;
     PAINTSTRUCT ps;
     TCHAR       szBuffer[10];
     TEXTMETRIC  tm;

     switch(message)
     {
     case WM_CREATE:
          hdc = GetDC(hwnd);

          GetTextMetrics(hdc, &tm);
          cxChar = tm.tmAveCharWidth;
          cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
          cyChar = tm.tmHeight + tm.tmExternalLeading;

          ReleaseDC(hwnd, hdc);

          SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE);
          return 0 ;
     case WM_SIZE:
          cyClient = HIWORD(lParam);
		  iVscrollMax = max(0, NUMLINES - cyClient/cyChar);
          SetScrollRange(hwnd, SB_VERT, 0, iVscrollMax, FALSE);
          return 0;
     case WM_VSCROLL:
          switch(LOWORD(wParam))
          {
          case SB_LINEUP:
               iVscrollPos -= 1;
               break;     
          case SB_LINEDOWN:
               iVscrollPos += 1;
               break;     
          case SB_PAGEUP:
               iVscrollPos -= cyClient / cyChar;
               break;     
          case SB_PAGEDOWN:
               iVscrollPos += cyClient / cyChar;
               break;     
          case SB_THUMBPOSITION:
               iVscrollPos = HIWORD(wParam);
               break;     
          default:
               break;
          }
		  // Get assured tha iVscrollPos is between min n max values:
          iVscrollPos = max(0, min(iVscrollPos, NUMLINES - (cyClient/cyChar)));
		  // if it has changed update tha new position:
          if(iVscrollPos != GetScrollPos(hwnd, SB_VERT))
          {
               SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE); // or SB_HORZ
               InvalidateRect(hwnd, NULL, TRUE); // Invalidates all the client area. So windows'll generate a WM_PAINT msg to be catched below, avoidin' repeatin' code this way.
			   UpdateWindow(hwnd); // Causes the window procedure to be called immediately with a WM_PAINT msg if any part of the client area is invalid (this case).
          }
		  //MessageBoxPrintf(TEXT("MessageBox Printf"),
			//						TEXT("cyClient = %i pixels wide"),
			//							cyClient);
          return 0;
     case WM_PAINT:
          hdc = BeginPaint(hwnd, &ps);     
          for(i = 0; i < NUMLINES; i++)
          {
               y = cyChar * (i - iVscrollPos);     
               TextOut(hdc, 0,           y, sysmetrics[i].szLabel, lstrlen(sysmetrics[i].szLabel));     
               TextOut(hdc, 22 * cxCaps, y, sysmetrics[i].szDesc,  lstrlen(sysmetrics[i].szDesc));     
               SetTextAlign (hdc, TA_RIGHT | TA_TOP);
               TextOut(hdc, 22 * cxCaps + 40 * cxChar, y, szBuffer, wsprintf(szBuffer, TEXT ("%5d"),
                                  GetSystemMetrics(sysmetrics[i].iIndex)));     
               SetTextAlign(hdc, TA_LEFT | TA_TOP);
          }
          EndPaint(hwnd, &ps);
          return 0;
     case WM_DESTROY:
          PostQuitMessage(0);
          return 0;
     }
     return DefWindowProc(hwnd, message, wParam, lParam);
}

