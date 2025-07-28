#include <windows.h>
/*******************  Global Variables ********************/
HINSTANCE  g_hInst = NULL;
HWND       g_hWnd  = NULL;
const char g_szClassName[] = "ClayClass";
/*********************  Prototypes  ***********************/
HRESULT          InitWindow(int);
LRESULT CALLBACK WndProc   (HWND, UINT, WPARAM, LPARAM);
/********************************************************************\
*  Purpose : Entry point to the program (like main in console app    *
*  Comments: Register window class, create and display the main      *
*            window, and enter message loop.                         *
\********************************************************************/
int CALLBACK WinMain(HINSTANCE _hInst, HINSTANCE _hPrevInst, LPSTR _lpszCmdLine, int _nCmdShow) {
	g_hInst = _hInst;
	if(FAILED(InitWindow(_nCmdShow)))
        return FALSE;

	MSG  msg = {0};
	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage (&msg); // Send the msg out to the window that the msg was sent to. This could be our main window, control, etc.
	}
	return (int)msg.wParam;
}

//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow(int _nCmdShow) {
    // Registering a window class:
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX); 
    wc.style          = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc    = WndProc;
    wc.cbClsExtra     = 0;
    wc.cbWndExtra     = 0;
    wc.hInstance      = g_hInst;
    wc.hIcon          = LoadIcon  (NULL, IDI_APPLICATION);
    wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground  = (HBRUSH)  (COLOR_WINDOW+1);
    wc.lpszMenuName   = NULL;
    wc.lpszClassName  = (LPCWSTR)g_szClassName;
    wc.hIconSm        = LoadIcon(NULL, IDI_APPLICATION);
    if(!RegisterClassEx(&wc))
        return E_FAIL;
    // Creating a window obj:
	int desktopwidth  = GetSystemMetrics(SM_CXSCREEN);	// Column
	int desktopheight = GetSystemMetrics(SM_CYSCREEN);	// Line

	g_hWnd = CreateWindowEx(			// If succeds returns a handle to the new window.
			0,							// Extended possibilities for variation.
			(LPCWSTR)g_szClassName,		// Classname. Must not be registered yet.
			L"Window Demo Application",	// Title bar name.
			WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL,//|WS_POPUP|WS_MINIMIZE|WS_MAXIMIZE, // Top level window.
			desktopwidth /4,		// Horizontal position in screen (pixels). If child relative with the client parent's area
			desktopheight/4,		// Vertical   position in screen (pixels)
			desktopwidth /2,		// CW_USEDEFAULT, // width in pixels
			desktopheight/2,		// CW_USEDEFAULT, // height in pixels
			HWND_DESKTOP,			// The window is a child-window to desktop */
			NULL,					// No owner window. No menu resouce (Use class menu)
			g_hInst,				// Handle to app instance.
			NULL);					// No window creation data (such as dlgs).
		
    if(!g_hWnd)	
        return E_FAIL;
    ShowWindow(g_hWnd, _nCmdShow);
   
    return S_OK;
}
/********************************************************************\
* Purpose : Processes Application Messages for this window           *
\********************************************************************/
LRESULT CALLBACK WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) {
	PAINTSTRUCT ps;
	HDC         hDC;			// Handle to Device Context (DC)

	switch(_msg) {
	  case WM_PAINT:			// Sent when must be redraw (full or partially)
		  hDC = BeginPaint(_hWnd, &ps);
		  TextOut (hDC, 10, 10, L"Hello, Windows!", 15);
		  EndPaint(_hWnd, &ps); // Release the DC
		  break;
	  case WM_DESTROY:			// Sent immidiately after destroyin the window. Finish processing tasks
		  PostQuitMessage(0);	// Post a WM_QUIT msg to the msg loop in WinMain. This causeS GetMessage() to return FALSE. 
		  break;
	  default:					// Let the default window proc handle all other messages
		  return(DefWindowProc(_hWnd, _msg, _wParam, _lParam));
	}
	return 0;
}