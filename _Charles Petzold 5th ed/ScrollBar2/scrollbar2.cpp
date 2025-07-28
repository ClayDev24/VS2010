/*----------------------------------------------------
   SYSMETS3.C -- System Metrics Display Program No. 3
                 (c) Charles Petzold, 1998
  ----------------------------------------------------*/
#include <windows.h>
#include "sysmets.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT("SysMets3");
     HWND		hwnd;
     MSG        msg ;
     WNDCLASS   wc;     
     wc.style         = CS_HREDRAW | CS_VREDRAW;
     wc.lpfnWndProc   = WndProc;
     wc.cbClsExtra    = 0;
     wc.cbWndExtra    = 0;
     wc.hInstance     = hInstance;
     wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
     wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
     wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
     wc.lpszMenuName  = NULL;
     wc.lpszClassName = szAppName;     
     if(!RegisterClass(&wc)) 
     {
          MessageBox(NULL, TEXT("Program requires Windows NT!"), 
                      szAppName, MB_ICONERROR);
          return 0;
     }
     hwnd = CreateWindow(szAppName, TEXT("Get System Metrics No. 3"),
                          WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL);
     ShowWindow(hwnd, iCmdShow);
     UpdateWindow(hwnd);     
     while(GetMessage(&msg, NULL, 0, 0))
     {
          TranslateMessage(&msg);
          DispatchMessage (&msg);
     }
     return msg.wParam;
} // WinMain()

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     static int  cxChar, cxCaps, cyChar, cxClient, cyClient, iMaxWidth;
     HDC         hdc ;
     int         i, x, y, iVertPos, iHorzPos, iPaintBeg, iPaintEnd;
     PAINTSTRUCT ps;
     SCROLLINFO  si;
     TEXTMETRIC  tm;
     TCHAR       szBuffer[10];     
     switch(message)
     {
     case WM_CREATE:
          hdc = GetDC(hwnd);
          
          GetTextMetrics(hdc, &tm);
          cxChar = tm.tmAveCharWidth;
          cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
          cyChar = tm.tmHeight + tm.tmExternalLeading;
          
          ReleaseDC(hwnd, hdc);
          // Save the width of the three columns          
          iMaxWidth = 40 * cxChar + 22 * cxCaps;
          return 0;

     case WM_SIZE:
          cxClient = LOWORD(lParam);
          cyClient = HIWORD(lParam);		  
		  // Set vertical scroll bar range and page size (doc contents)
          si.cbSize = sizeof(si); // Size of the structure
          si.fMask  = SIF_RANGE | SIF_PAGE;
          si.nMin   = 0;
          si.nMax   = NUMLINES - 1;
          si.nPage  = cyClient / cyChar; // PS
          SetScrollInfo(hwnd, SB_VERT, &si, TRUE);		  
		  // Set horizontal scroll bar range and page size
          si.cbSize = sizeof(si);
          si.fMask  = SIF_RANGE | SIF_PAGE;
          si.nMin   = 0;
          si.nMax   = 2 + iMaxWidth / cxChar;	// 2 space left-asided at the right end.
          si.nPage  = cxClient / cxChar;		// Page Size wide
          SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
          return 0;          
     case WM_VSCROLL:
		 // Get all the vertical scroll bar information
          si.cbSize = sizeof(si);
          si.fMask  = SIF_ALL;
          GetScrollInfo(hwnd, SB_VERT, &si);		  
		  // Save the position for comparison later on
          iVertPos = si.nPos;
          switch(LOWORD(wParam))
          {
          case SB_TOP:
               si.nPos = si.nMin;
               break;               
          case SB_BOTTOM:
               si.nPos = si.nMax;
               break;               
          case SB_LINEUP:
               si.nPos -= 1;
               break ;               
          case SB_LINEDOWN:
               si.nPos += 1;
               break;               
          case SB_PAGEUP:
               si.nPos -= si.nPage;
               break;
          case SB_PAGEDOWN:
               si.nPos += si.nPage;
               break;               
          case SB_THUMBTRACK: // Windows wont scrolls the contents until user release the mouse button. For this purpose use rather comples SB_THUMBTRACK
               si.nPos = si.nTrackPos;
               break;               
          default:
               break ;         
          }
		  // Set the position and then retrieve it.  Due to adjustments
		  // by Windows it may not be the same as the value set.
          si.fMask = SIF_POS;
          SetScrollInfo(hwnd, SB_VERT, &si, TRUE);
          GetScrollInfo(hwnd, SB_VERT, &si);		  
		  // If the position has changed, scroll the window and update it
          if(si.nPos != iVertPos)
          {                    
			  // The third argument sets the new vertical position:
               ScrollWindow(hwnd, 0, cyChar * (iVertPos - si.nPos), NULL, NULL);
               UpdateWindow(hwnd);
          }
          return 0;          
     case WM_HSCROLL:
		 // Get all the vertical scroll bar information
          si.cbSize = sizeof(si);
          si.fMask  = SIF_ALL;
		  // Save the position for comparison later on
          GetScrollInfo(hwnd, SB_HORZ, &si);
          iHorzPos = si.nPos;
          switch(LOWORD(wParam))
          {
          case SB_LINELEFT:
               si.nPos -= 1;
               break;               
          case SB_LINERIGHT:
               si.nPos += 1;
               break;               
          case SB_PAGELEFT:
               si.nPos -= si.nPage;
               break;               
          case SB_PAGERIGHT:
               si.nPos += si.nPage;
               break;               
          case SB_THUMBPOSITION: // Windows wont scrolls the contents until user release the mouse button. For this purpose use rather comples SB_THUMBTRACK
               si.nPos = si.nTrackPos;
               break;               
          default:
               break;
          }
		  // Set the position and then retrieve it.  Due to adjustments
		  // by Windows it may not be the same as the value set.
          si.fMask = SIF_POS;
          SetScrollInfo(hwnd, SB_HORZ, &si, TRUE);
          GetScrollInfo(hwnd, SB_HORZ, &si);		  
		  // If the position has changed, scroll the window 
          if(si.nPos != iHorzPos) {
			  // The second argument sets the new horizontal position:
               ScrollWindow(hwnd, cxChar * (iHorzPos - si.nPos), 0, NULL, NULL);
			   UpdateWindow(hwnd);
		  }
          return 0;
     case WM_PAINT:
          hdc = BeginPaint(hwnd, &ps);
		  // Get vertical scroll bar position
          si.cbSize = sizeof(si);
          si.fMask  = SIF_POS;
          GetScrollInfo(hwnd, SB_VERT, &si);
          iVertPos = si.nPos;
		  // Get horizontal scroll bar position
          GetScrollInfo(hwnd, SB_HORZ, &si);
          iHorzPos = si.nPos;
		  // Find painting limits
          iPaintBeg = max(0, iVertPos + ps.rcPaint.top / cyChar);
          iPaintEnd = min(NUMLINES - 1, iVertPos + ps.rcPaint.bottom / cyChar);          
          for(i = iPaintBeg; i <= iPaintEnd; i++)
          {
               x = cxChar * (1 - iHorzPos);
               y = cyChar * (i - iVertPos);               
               TextOut(hdc, x, y, sysmetrics[i].szLabel, lstrlen(sysmetrics[i].szLabel));               
               TextOut(hdc, x + 22 * cxCaps, y, sysmetrics[i].szDesc, lstrlen(sysmetrics[i].szDesc));
               
               SetTextAlign(hdc, TA_RIGHT | TA_TOP);
               
               TextOut(hdc, x + 22 * cxCaps + 40 * cxChar, y, szBuffer, wsprintf(szBuffer, TEXT ("%5d"),
                             GetSystemMetrics(sysmetrics[i].iIndex))) ;
               SetTextAlign (hdc, TA_LEFT | TA_TOP) ;
          }
          EndPaint(hwnd, &ps);
          return 0;          
     case WM_DESTROY:
          PostQuitMessage(0);
          return 0;
     }
     return DefWindowProc(hwnd, message, wParam, lParam);
}

