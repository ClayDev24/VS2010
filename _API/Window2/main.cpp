#include <windows.h>  
//##############################################################
// GLOBALS:
//##############################################################
HINSTANCE g_hinst; 
// PROTOTYPES: 
BOOL InitApp (); 
BOOL InitInst(int); 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
//##############################################################
// App. ENTRE Point:
int WINAPI WinMain(HINSTANCE _hinst, HINSTANCE _hPrevInst, LPSTR _lpCmdLine, int _nCmdShow) {
	g_hinst = _hinst; 
    if (!InitApp()) 
        return FALSE; 
    if(!InitInst(_nCmdShow)) 
        return FALSE; 
	MSG msg;
    while(GetMessage(&msg, (HWND)NULL, 0, 0)) {
        TranslateMessage(&msg); 
        DispatchMessage (&msg); 
    }
    return msg.wParam; 
        //UNREFERENCED_PARAMETER(_lpCmdLine); 
} 
//##############################################################
BOOL InitApp() {    
    // Fillin' window class attibutes:
	WNDCLASSEX wcx; 
    wcx.cbSize = sizeof(wcx);			// size of structure 
    wcx.style  = CS_HREDRAW|CS_VREDRAW;	// redraw if size changes 
    wcx.lpfnWndProc = WndProc;			// points to window procedure 
    wcx.cbClsExtra  = 0;				// no extra class memory 
    wcx.cbWndExtra  = 0;				// no extra window memory 
    wcx.hInstance = g_hinst;			// handle to instance 
    wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);// predefined app. icon 
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);  // predefined arrow 
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // white background brush 
    wcx.lpszMenuName  = (LPCSTR)"MainMenu";		// name of menu resource 
    wcx.lpszClassName = (LPCSTR)"MainWClass";	// name of window class 
    wcx.hIconSm = (HICON)LoadImage(g_hinst,		// small class icon 
        MAKEINTRESOURCE(5),IMAGE_ICON,
        GetSystemMetrics(SM_CXSMICON), 
        GetSystemMetrics(SM_CYSMICON), 
        LR_DEFAULTCOLOR); 
    // Register the window class:
    return RegisterClassEx(&wcx); 
} 
//##############################################################
BOOL InitInst(int _nCmdShow) {
    HWND hwnd; 
    // Create the main window. 
    hwnd = CreateWindow( 
        "MainWClass",		// name of window class 
        "Sample",			// title-bar string 
        WS_OVERLAPPEDWINDOW,// top-level window 
        CW_USEDEFAULT,      // default horizontal position 
        CW_USEDEFAULT,      // default vertical position 
        CW_USEDEFAULT,      // default width 
        CW_USEDEFAULT,      // default height 
        (HWND) NULL,        // no owner window 
        (HMENU) NULL,       // use class menu 
        g_hinst,            // handle to application instance 
        (LPVOID) NULL);     // no window-creation data 
 
    if (!hwnd) 
        return FALSE;
    // Show the window and send a WM_PAINT message to the WinProc:
    ShowWindow(hwnd, _nCmdShow); 
    UpdateWindow(hwnd); 
    return TRUE; 
}
//##############################################################
LRESULT CALLBACK WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) {
	PAINTSTRUCT ps;
	HDC         hDC;			// Handle to Device Context (DC)

	switch(_msg) {
	  case WM_PAINT:			// Sent when must be redraw (full or partially)
		  hDC = BeginPaint(_hWnd, &ps);
		  TextOut (hDC, 10, 10, "Hello, Windows!", 15);
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