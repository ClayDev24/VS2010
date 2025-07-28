#include <windows.h>
#include "IDs.h"
/*********************  Prototypes  ***********************/
LRESULT CALLBACK WndProc     (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);
/*******************  Global Variables ********************/
HWND		g_hWnd  = NULL;
HINSTANCE	g_hInst = NULL;
const char	g_szClassName[] = "ClayClass";
//********************************************************************
int CALLBACK WinMain(HINSTANCE _hInst, HINSTANCE _hPrevInst, LPSTR _lpszCmdLine, int _nCmdShow) {
	g_hInst = _hInst;
	// Filling the WNDCLASS struct w/ class info:
	if(!_hPrevInst) {
		WNDCLASSEX wc;
		wc.lpszClassName = (LPCSTR)g_szClassName;
		wc.lpfnWndProc   = WndProc; // Every window must have a window procedure. Its name is user-defined.
		wc.style       = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
		wc.hInstance   = g_hInst;
		wc.hIcon       = LoadIcon  (NULL, IDI_APPLICATION);
		wc.hIconSm     = LoadIcon  (NULL, IDI_APPLICATION);
		wc.hCursor     = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszMenuName  = NULL; // No menu
		wc.cbClsExtra    = 0;	 // No extra bytes sfter the window class structure
		wc.cbWndExtra    = 0;	 // or the window instance.
		wc.cbSize        = sizeof(WNDCLASSEX);
		if(!RegisterClassEx(&wc)) {
			MessageBox(HWND_DESKTOP, "Failed to register wnd class", "Button Demo Application", MB_OK|MB_ICONEXCLAMATION);
			return -1;
		}
	}

	int desktopwidth  = GetSystemMetrics(SM_CXSCREEN);
	int desktopheight = GetSystemMetrics(SM_CYSCREEN);
	g_hWnd = CreateWindowEx(			// If succeds returns a handle to the new window.
		0,								// Extended possibilities for variation.
		(LPCSTR)g_szClassName,			// Classname. Must not be registered yet.
		TEXT("Button Demo Application"),// Title bar name.
		WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL,//|WS_POPUP|WS_MINIMIZE|WS_MAXIMIZE, // Top level window.
		desktopwidth /4,	// Horizontal position in screen (pixels). If child relative with the client parent's area
		desktopheight/4,	// Vertical   position in screen (pixels)
		desktopwidth /2,	// CW_USEDEFAULT, // width in pixels
		desktopheight/2,	// CW_USEDEFAULT, // height in pixels
		HWND_DESKTOP,       // The window is a child-window to desktop */
		NULL,				// No owner window. No menu resouce (Use class menu)
		g_hInst,			// Handle to app instance.
		NULL				// No window creation data (such as dlgs).
		);
	
	if(!g_hWnd) {
		MessageBox(g_hWnd, "Failed to create window", "Button Demo Application", MB_OK|MB_ICONEXCLAMATION);
		return -1;
	}
	// Show the window and send a WM_PAINT msg to the window procedure.
	ShowWindow	(g_hWnd, _nCmdShow);
	UpdateWindow(g_hWnd);

	MSG  msg;
	BOOL fGotMsg;
	while((fGotMsg = GetMessage(&msg, NULL, 0, 0)) != 0) {
		if(fGotMsg == -1) { /*handle the error and possibly exit*/ }
		TranslateMessage(&msg); // Translate virtual-key messages into character messages.
		DispatchMessage (&msg); // Send the msg out to the window that the msg was sent to. This could be main window (MainWinProc), control, etc.
	}
	return msg.wParam;
}
//********************************************************************
LRESULT CALLBACK WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) {
	PAINTSTRUCT ps;
	HDC         hDC;		// Handle to Device Context (DC)
	HWND		hButton1;
	HWND		hButton2;

	switch(_msg) {
		case WM_CREATE:
			hButton1 = CreateWindowEx(0,				// more or ''extended'' styles
				TEXT("BUTTON"),                         // Control ''class'' to create
				TEXT("Button 1"),                       // Control caption
				WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,   // control styles separated by |
				10,                                     // Left pos in pixels
				10,                                     // Top pos in pixels
				200,                                    // WIDTH
				30,                                     // HEIGHT
				_hWnd,                                   // Parent window handle
				(HMENU)IDBUTTON1,                       // control''s ID for WM_COMMAND
				g_hInst,								// application instance
				NULL);
			hButton2 = CreateWindowEx(0,				// more or ''extended'' styles
				TEXT("BUTTON"),                         // Control ''class'' to create
				TEXT("Button 2"),                       // Control caption
				WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,   // control styles separated by |
				210,                                    // Left pos in pixels
				10,                                     // Top pos in pixels
				200,                                    // WIDTH
				30,                                     // HEIGHT
				_hWnd,									// Parent window handle
				(HMENU)IDBUTTON2,                       // control''s ID for WM_COMMAND
				g_hInst,								// application instance
				NULL);
			break;
		case WM_PAINT:	// Sent when must be redraw (full or partially)
			hDC = BeginPaint(_hWnd, &ps);
			TextOut (hDC, 10, 10, TEXT("Hello, Windows!"), 15);
			EndPaint(_hWnd, &ps ); // Release the DC
			break;
		case WM_COMMAND:	// Item selected from menu
			switch(_wParam) {
				case IDM_ABOUT:
					// This func takes a template (Generic.dlg file) to create a dialog box:
					DialogBox(g_hInst, TEXT("ClayDlg"),	// The name of the source
					_hWnd, (DLGPROC)AboutDlgProc);			// A pointer to AboutDlgProc procedure. That deals with its own msgs
				break;
                case IDBUTTON1:
                    MessageBox(_hWnd, "Button 1!", "My Program!", MB_OK|MB_ICONEXCLAMATION);
					break;
                case IDBUTTON2:
                    MessageBox(_hWnd, "Button 2!", "My Program!", MB_OK|MB_ICONEXCLAMATION);
					break;
			}
			break;
		case WM_DESTROY:			// Sent immidiately after destroyin the window. Finish processing tasks
			PostQuitMessage(0);	// Post a WM_QUIT msg to the msg loop in WinMain. This causeS GetMessage() to return FALSE. 
			break;
			/**************************************************************\
			*     Let the default window proc handle all other messages    *
			\**************************************************************/
		default:
			return(DefWindowProc(_hWnd,_msg, _wParam, _lParam));
	}
	return 0;
}
//********************************************************************
INT_PTR CALLBACK AboutDlgProc(HWND _hDlg, UINT _uMsg, WPARAM _wParam, LPARAM _lParam ) {
	switch(_uMsg) {
	  case WM_INITDIALOG:
		  return TRUE;
	  case WM_COMMAND:
		  switch(_wParam) {
	  case IDOK:
		  EndDialog(_hDlg, TRUE);
		  return TRUE;
		  }
		  break;
	}
	return FALSE;
}