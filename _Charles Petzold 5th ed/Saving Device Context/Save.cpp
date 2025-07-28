// Rectangle2.cpp
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

#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 300
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
	switch(msg)
	{	
    case WM_SIZE: // Sent when window is first load.
        cxClient = LOWORD(lparam);
        cyClient = HIWORD(lparam);		  
		break;
	case WM_PAINT: 		
   	    hdc = BeginPaint(hwnd,&ps);	// simply validate the window                 
        EndPaint(hwnd,&ps);			// end painting        
		return(0);					// return success
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
	if (!RegisterClassEx(&wc))
		return(0);
	// create the window
	if (!(hwnd = CreateWindowEx(NULL,// extended style
		WINDOW_CLASS_NAME,			 // window class name
		"Circles Drawing Demo",		 // title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,0,						 // initial x,y
		WINDOW_WIDTH, WINDOW_HEIGHT, // initial width n height
		NULL, NULL,					 // handle to parent n menu
		hinstance,					 // instance of this application
		NULL)))						 // extra creation parms
		return(0);
	
	main_window_handle = hwnd; // save main window handle
	// enter main event loop, but this time we use PeekMessage()
	// instead of GetMessage() to retrieve messages
	
	// get the graphics device context 
	hdc = GetDC(hwnd);
	int idSavedDC = SaveDC(hdc);
	// enter main event loop, but this time we use PeekMessage()
	// instead of GetMessage() to retrieve messages
	while(TRUE)
	{
		// test if there is a message in queue, if so get it
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// test if this is a quit
			if(msg.message == WM_QUIT)
				break;	   
			TranslateMessage(&msg); // translate any accelerator keys	   
			DispatchMessage(&msg);  // send the message to the window proc
		}
		// select random colors for polygon 
		HPEN   pen_color   = CreatePen(PS_SOLID, 1, RGB(rand()%256,rand()%256,rand()%256));
		HBRUSH brush_color = CreateSolidBrush(RGB(rand()%256,rand()%256,rand()%256));
		// select them into dc
		SelectObject(hdc,pen_color);
		SelectObject(hdc,brush_color);
		// now create list of random points for polygon
		int num_points = 3+rand()%8;
		// this will hold the point list
		POINT point_list[10];
		// create array of points
		for(int index = 0; index < num_points; index++)
		{
			// set next random point in list
			point_list[index].x = rand()%WINDOW_WIDTH;
			point_list[index].y = rand()%WINDOW_HEIGHT;
		}    
		// draw the polygon
		Polygon(hdc, point_list, num_points);
		// let user see it
		Sleep(500);

		// Polygon with default attributes:
		RestoreDC(hdc, idSavedDC);
		for(index = 0; index < num_points; index++)
		{
			// set next random point in list
			point_list[index].x = rand()%WINDOW_WIDTH;
			point_list[index].y = rand()%WINDOW_HEIGHT;
		}    
		// draw the polygon
		Polygon(hdc, point_list, num_points);
		// let user see it
		Sleep(500);
		// main game processing goes here
		if (KEYDOWN(VK_ESCAPE))
			SendMessage(hwnd, WM_CLOSE, 0,0);       
	} // while
	
	// release the device context
	ReleaseDC(hwnd,hdc);
	return(msg.wParam); // return to Windows like this
} // WinMain()
///////////////////////////////////////////////////////////

