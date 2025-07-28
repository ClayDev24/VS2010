// Lines.cpp
// INCLUDES ///////////////////////////////////////////////
#include <windows.h>   // include all the windows headers
#include <windowsx.h>  // include useful macros
#include <mmsystem.h>  // very important and include WINMM.LIB too!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// DEFINES ////////////////////////////////////////////////
#define WIN32_LEAN_AND_MEAN  // just say no to MFC
// defines for windows 
#define WINDOW_CLASS_NAME "WINCLASS1"

// MACROS /////////////////////////////////////////////////
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

// GLOBALS ////////////////////////////////////////////////
HWND      main_window_handle = NULL; // globally track main window
int cxClient, cyClient;

HINSTANCE hinstance_app      = NULL; // globally track hinstance
char buffer[80];                     // general printing buffer

// FUNCTIONS //////////////////////////////////////////////
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) // this is the main message handler of the system
{
	PAINTSTRUCT	ps;		// used in WM_PAINT
	HDC			hdc;	// handle to a device context
	int x, y;
	switch(msg)
	{	
    case WM_SIZE: // Sent when window is first load.
        cxClient = LOWORD(lparam);
        cyClient = HIWORD(lparam);		  
		break;
	case WM_PAINT: 		
   	    hdc = BeginPaint(hwnd,&ps);	// simply validate the window                 
		
		HPEN hpen, old_pen;
		hpen = CreatePen(PS_SOLID, rand()%10, RGB(rand()%256,rand()%256,rand()%256));	
		old_pen = (HPEN) SelectObject(hdc, hpen);
		RECT rect;
		GetClientRect(hwnd, &rect);
		// drawing a grid of lines:
		for(x = 0; x < rect.right; x += 100) {
			MoveToEx(hdc, x, 0, NULL); // sets 'current position' attribute of device context (GDI). The las'parameter is a point structure to be used to return the previous current position. if ya dont need this kinda info jus'set it to NULL.
			// Default current position in GDI device contex (hdc) is (0, 0)
			LineTo(hdc, x, rect.bottom); // dras a line from current position to its settings positions.
		}
		for(y = 0; y < rect.bottom; y += 100) {
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, rect.right, y);
		}

		POINT pt;
		// if ya ever need the currente position:
		GetCurrentPositionEx(hdc, &pt);

		// Restorin' olds:
		SelectObject(hdc, old_pen);
		// now delete the brush
		DeleteObject(hpen);    
		// release the device context

        EndPaint(hwnd,&ps);	// end painting        
		return(0);			// return success
	case WM_DESTROY: 
		PostQuitMessage(0);
		return(0);
		break;
	default:break;
    }
	return(DefWindowProc(hwnd, msg, wparam, lparam)); // process any messages that we didn't take care of 
} // WindowProc()

// WINMAIN ////////////////////////////////////////////////
int WINAPI WinMain(	HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpcmdline, int ncmdshow)
{
	WNDCLASSEX wc;	// this will hold the class we create
	HWND	   hwnd;// generic window handle
	MSG		   msg;	// generic message
	HDC        hdc; // graphics device context
	// first fill in the window class stucture
	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style		 = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc	 = WindowProc;
	wc.cbClsExtra	 = wc.cbWndExtra = 0;
	wc.hInstance	 = hinstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW); 
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName	 = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	// save hinstance in global
	hinstance_app = hinstance;
	// register the window class
	if(!RegisterClassEx(&wc))
		return(0);
	// create the window
	if(!(hwnd = CreateWindowEx(NULL,						// extended style
		WINDOW_CLASS_NAME,			// window class name
		"Lines Drawing Demo",	// title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,0,						// initial x,y
		500, 500,					// initial width n height
		NULL, NULL,					// handle to parent n menu
		hinstance,					// instance of this application
		NULL)))						// extra creation parms
		return(0);
	
	main_window_handle = hwnd; // save main window handle
	// enter main event loop, but this time we use PeekMessage()
	// instead of GetMessage() to retrieve messages
	while(TRUE)
	{    
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) // test if there is a message in queue, if so get it
		{
			if(msg.message == WM_QUIT) // test if this is a quit
				break;		   
			TranslateMessage(&msg); // translate any accelerator keys	   
			DispatchMessage(&msg);  // send the message to the window proc
		}
		// main game processing goes here
		if(KEYDOWN(VK_ESCAPE))
			SendMessage(hwnd, WM_CLOSE, 0,0);       
	} // while
	return(msg.wParam); // return to Windows like this
} // WinMain()
///////////////////////////////////////////////////////////

