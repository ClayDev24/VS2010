/*#include <windows.h>
#include "IDs.h"
//********************  Prototypes  ***********************
LRESULT CALLBACK MainWndProc ( HWND, UINT, WPARAM, LPARAM );
INT_PTR CALLBACK AboutDlgProc( HWND, UINT, WPARAM, LPARAM );
//******************  Global Variables ********************
HINSTANCE ghInstance;
const char g_szClassName[] = "ClayClass";
//********************************************************************
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
WNDCLASSEX wc;
wc.lpszClassName = (LPCSTR)g_szClassName;
wc.lpfnWndProc   = MainWndProc; // Every window must have a window procedure. Its name is user-defined.
wc.style       = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
wc.hInstance   = hInstance;
wc.hIcon       = LoadIcon  (NULL, IDI_APPLICATION);
wc.hIconSm     = LoadIcon  (NULL, IDI_APPLICATION);
wc.hCursor     = LoadCursor(NULL, IDC_ARROW );
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
wc.lpszMenuName  = NULL; // No menu
wc.cbClsExtra    = 0;	 // No extra bytes sfter the window class structure
wc.cbWndExtra    = 0;	 // or the window instance.
wc.cbSize        = sizeof(WNDCLASSEX);
if(!RegisterClassEx(&wc)) {
MessageBox(HWND_DESKTOP, "Failed to register wnd class", "Button Demo Application", MB_OK|MB_ICONEXCLAMATION);
return -1;
}

int desktopwidth  = GetSystemMetrics(SM_CXSCREEN);
int desktopheight = GetSystemMetrics(SM_CYSCREEN);
ghInstance = hInstance;
HWND hWnd  = CreateWindowEx(			// If succeds returns a handle to the new window.
0,									// Extended possibilities for variation.
(LPCSTR)g_szClassName,				// Classname. Must not be registered yet.
TEXT("Framework Demo Application"),	// Title bar name.
WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL,	//|WS_POPUP|WS_MINIMIZE|WS_MAXIMIZE, // Top level window.
desktopwidth /4,	// Horizontal position in screen (pixels). If child relative with the client parent's area
desktopheight/4,	// Vertical   position in screen (pixels)
desktopwidth /2,	// CW_USEDEFAULT, // width in pixels
desktopheight/2,	// CW_USEDEFAULT, // height in pixels
HWND_DESKTOP,       // The window is a child-window to desktop
NULL,				// No owner window. No menu resouce (Use class menu)
hInstance,			// Handle to app instance.
NULL				// No window creation data (such as dlgs).
);

if(!hWnd) {
MessageBox(hWnd, "Failed to create window", "Button Demo Application", MB_OK|MB_ICONEXCLAMATION);
return -1;
}

// Show the window and send a WM_PAINT msg to the window procedure.
ShowWindow(hWnd, nCmdShow);
UpdateWindow(hWnd);

MSG  msg;
BOOL fGotMsg;
while((fGotMsg = GetMessage(&msg, NULL, 0, 0)) != 0) {
if (fGotMsg == -1) {} //handle the error and possibly exit
TranslateMessage(&msg); // Translate virtual-key messages into character messages.
DispatchMessage (&msg); // Send the msg out to the window that the msg was sent to. This could be main window (MainWinProc), control, etc.
}
return msg.wParam;
}
//********************************************************************
LRESULT CALLBACK MainWndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam ) {
PAINTSTRUCT ps;
HDC         hDC;		// Handle to Device Context (DC)
HWND		hButton1;
HWND		hButton2;

switch( msg ) {
case WM_CREATE:
hButton1 = CreateWindowEx(0,				// more or ''extended'' styles
TEXT("BUTTON"),                         // Control ''class'' to create
TEXT("Button 1"),                       // Control caption
WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,   // control styles separated by |
10,                                     // Left pos in pixels
10,                                     // Top pos in pixels
200,                                    // WIDTH
30,                                     // HEIGHT
hWnd,                                   // Parent window handle
(HMENU)IDBUTTON1,                       // control''s ID for WM_COMMAND
ghInstance,                             // application instance
NULL);
hButton2 = CreateWindowEx(0,				// more or ''extended'' styles
TEXT("BUTTON"),                         // Control ''class'' to create
TEXT("Button 2"),                       // Control caption
WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,   // control styles separated by |
210,                                    // Left pos in pixels
10,                                     // Top pos in pixels
200,                                    // WIDTH
30,                                     // HEIGHT
hWnd,                                   // Parent window handle
(HMENU)IDBUTTON2,                       // control''s ID for WM_COMMAND
ghInstance,                             // application instance
NULL);
break;
case WM_PAINT:	// Sent when must be redraw (full or partially)
hDC = BeginPaint( hWnd, &ps );
TextOut( hDC, 10, 10, TEXT("Hello, Windows!"), 15 );
EndPaint( hWnd, &ps ); // Release the DC
break;
case WM_COMMAND:	// Item selected from menu
switch( wParam ) {
case IDM_ABOUT:
// This func takes a template (Generic.dlg file) to create a dialog box:
DialogBox( ghInstance, TEXT("ClayDlg"),		// The name of the source
hWnd, (DLGPROC) AboutDlgProc );	// A pointer to AboutDlgProc procedure. That deals with its own msgs
break;

case IDBUTTON1:
MessageBox(hWnd, (LPCTSTR)"Button 1!",  (LPCTSTR) "My Program!", MB_OK|MB_ICONEXCLAMATION);
break;
case IDBUTTON2:
MessageBox(hWnd, (LPCTSTR)"Button 2!",  (LPCTSTR) "My Program!", MB_OK|MB_ICONEXCLAMATION);
break;

}
break;
case WM_DESTROY:			// Sent immidiately after destroyin the window. Finish processing tasks
PostQuitMessage( 0 );	// Post a WM_QUIT msg to the msg loop in WinMain. This causeS GetMessage() to return FALSE. 
break;
//**************************************************************
//    Let the default window proc handle all other messages    *
//**************************************************************
default:
return( DefWindowProc( hWnd, msg, wParam, lParam ));
}
return 0;
}
//*********************************************************************
// Function: INT_PTR CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM)*
// Purpose : Processes "About" Dialog Box Messages                    *
//*********************************************************************
INT_PTR CALLBACK AboutDlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
switch( uMsg ) {
case WM_INITDIALOG:
return TRUE;
case WM_COMMAND:
switch( wParam ) {
case IDOK:
EndDialog( hDlg, TRUE );
return TRUE;
}
break;
}
return FALSE;
}
*/

//=============================================================================
//API functions used: CreateWindowEx,DefWindowProc,DispatchMessage,GetMessage,
//GetSystemMetrics,LoadImage,MessageBox,PostQuitMessage,RegisterClassEx,
//SendMessage,ShowWindow,UpdateWindow,TranslateMessage,WinMain.
//=============================================================================
//This demonstrates the creation of the following button types: default push 
//button,push button,check box,radio button and groupbox. The image style of 
//'bitmap' buttons (BS_BITMAP) and 'icon' buttons (BS_ICON) can be used in 
//conjunction with other button styles to create image checkboxes, radio 
//buttons etc. The default is a push button.
//=============================================================================
#if defined _MSC_VER || defined __BORLANDC__
#define OEMRESOURCE
#endif

#include <windows.h>  //include all the basics
#include <tchar.h>    //string and other mapping macros
#include <string>

//define an unicode string type alias
typedef std::basic_string<TCHAR> ustring;
//=============================================================================
//message processing function declarations
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int OnCreate(const HWND,CREATESTRUCT*);

//non-message function declarations
HWND CreateButton(const HWND,const HINSTANCE,DWORD,const RECT&,const int, const ustring&);
inline int ErrMsg(const ustring&);

//setup some button id's
enum {
	IDBC_DEFPUSHBUTTON=200,
	IDBC_PUSHBUTTON,
	IDBC_AUTOCHECKBOX,
	IDBC_AUTORADIOBUTTON,
	IDBC_GROUPBOX,
	IDBC_ICON,
	IDBC_BITMAP
};

//=============================================================================
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR pStr,int nCmd) {
	ustring classname=_T("SIMPLEWND");
	WNDCLASSEX wcx={0};  //used for storing information about the wnd 'class'

	wcx.cbSize         = sizeof(WNDCLASSEX);           
	wcx.lpfnWndProc    = WndProc;             //wnd Procedure pointer
	wcx.hInstance      = hInst;               //app instance
	//use 'LoadImage' to load wnd class icon and cursor as it supersedes the 
	//obsolete functions 'LoadIcon' and 'LoadCursor', although these functions will 
	//still work. Because the icon and cursor are loaded from system resources ie 
	//they are shared, it is not necessary to free the image resources with either 
	//'DestroyIcon' or 'DestroyCursor'.
	wcx.hIcon         = reinterpret_cast<HICON>(LoadImage(0,IDI_APPLICATION,
		IMAGE_ICON,0,0,LR_SHARED));
	wcx.hCursor       = reinterpret_cast<HCURSOR>(LoadImage(0,IDC_ARROW,
		IMAGE_CURSOR,0,0,LR_SHARED));
	wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE+1);   
	wcx.lpszClassName = classname.c_str(); 
	//the window 'class' (not c++ class) has to be registered with the system
	//before windows of that 'class' can be created
	if (!RegisterClassEx(&wcx)) {
		ErrMsg(_T("Failed to register wnd class"));
		return -1;
	}

	int desktopwidth=GetSystemMetrics(SM_CXSCREEN);
	int desktopheight=GetSystemMetrics(SM_CYSCREEN);

	HWND hwnd=CreateWindowEx(0,                     //extended styles
		classname.c_str(),     //name: wnd 'class'
		_T("Button Controls"), //wnd title
		WS_OVERLAPPEDWINDOW,   //wnd style
		desktopwidth/4,        //position:left
		desktopheight/4,       //position: top
		desktopwidth/2,        //width
		desktopheight/2,       //height
		0,                     //parent wnd handle
		0,                     //menu handle/wnd id
		hInst,                 //app instance
		0);                    //user defined info
	if (!hwnd) {
		ErrMsg(_T("Failed to create wnd"));
		return -1;
	}

	ShowWindow(hwnd,nCmd); 
	UpdateWindow(hwnd);
	//start message loop - windows applications are 'event driven' waiting on user,
	//application or system signals to determine what action, if any, to take. Note 
	//that an error may cause GetMessage to return a negative value so, ideally,  
	//this result should be tested for and appropriate action taken to deal with 
	//it(the approach taken here is to simply quit the application).
	MSG msg;
	while (GetMessage(&msg,0,0,0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}
//=============================================================================
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		return OnCreate(hwnd,reinterpret_cast<CREATESTRUCT*>(lParam));
	case WM_DESTROY:
		PostQuitMessage(0);    //signal end of application
		return 0;
	default:
		//let system deal with msg
		return DefWindowProc(hwnd,uMsg,wParam,lParam);  
	}
}
//=============================================================================
int OnCreate(const HWND hwnd,CREATESTRUCT *cs) {
	//handles the WM_CREATE message of the main, parent window; return -1 to fail
	//window creation
	RECT rc={10,10,200,40};
	//the various button types are created by simply varying the style bits
	CreateButton(hwnd,cs->hInstance,BS_DEFPUSHBUTTON,rc,IDBC_DEFPUSHBUTTON,
		_T("DEFAULT PUSH BUTTON"));

	rc.top+=50;
	CreateButton(hwnd,cs->hInstance,BS_PUSHBUTTON,rc,IDBC_PUSHBUTTON,
		_T("PUSH BUTTON"));

	rc.top+=50;
	CreateButton(hwnd,cs->hInstance,BS_AUTOCHECKBOX,rc,IDBC_AUTOCHECKBOX,
		_T("CHECK BOX"));

	rc.top+=50;
	CreateButton(hwnd,cs->hInstance,BS_AUTORADIOBUTTON,rc,IDBC_AUTOCHECKBOX,
		_T("RADIO BUTTON"));

	rc.top=10;
	rc.left=240;
	CreateButton(hwnd,cs->hInstance,BS_GROUPBOX,rc,IDBC_GROUPBOX,
		_T("GROUP BOX"));

	rc.top+=50;
	HWND hIconBtn=CreateButton(hwnd,cs->hInstance,BS_ICON,rc,IDBC_ICON,
		_T("ICON BUTTON - NO TEXT"));
	//get and assign the icon. Because LR_SHARED is used with a system 
	//resource, there is no need to use DestroyIcon to free icon resources 
	//when finshed with the icon.
	HICON hIcon=reinterpret_cast<HICON>(LoadImage(0,IDI_EXCLAMATION,IMAGE_ICON, 0,0,LR_SHARED));
	SendMessage(hIconBtn,BM_SETIMAGE,IMAGE_ICON,reinterpret_cast<LPARAM>(hIcon));

	rc.top+=50;
	HWND hBmpBtn=CreateButton(hwnd,cs->hInstance,BS_BITMAP,rc,IDBC_BITMAP,_T("BITMAP BUTTON - NO TEXT"));

	//get and assign the bitmap. Because LR_SHARED is used with a system 
	//resource, there is no need to use DeleteObject to free bitmap
	//resources when finshed with the bitmap.
	HBITMAP hBmp=reinterpret_cast<HBITMAP>(LoadImage(0,MAKEINTRESOURCE(OBM_CHECK),
		IMAGE_BITMAP,0,0,LR_SHARED));
	SendMessage(hBmpBtn,BM_SETIMAGE,IMAGE_BITMAP,reinterpret_cast<LPARAM>(hBmp));
	return 0;
}
//=============================================================================
inline int ErrMsg(const ustring& s) {
	return MessageBox(0,s.c_str(),_T("ERROR"),MB_OK|MB_ICONEXCLAMATION);
}
//=============================================================================
HWND CreateButton(const HWND hParent,const HINSTANCE hInst,DWORD dwStyle,
				  const RECT& rc,const int id,const ustring& caption)
{
	dwStyle|=WS_CHILD|WS_VISIBLE;
	return CreateWindowEx(0,                            //extended styles
		_T("button"),                 //control 'class' name
		caption.c_str(),              //control caption
		dwStyle,                      //control style 
		rc.left,                      //position: left
		rc.top,                       //position: top
		rc.right,                     //width
		rc.bottom,                    //height
		hParent,                      //parent window handle
		//control's ID
		reinterpret_cast<HMENU>(static_cast<INT_PTR>(id)),
		hInst,                        //application instance
		0);                           //user defined info
}
//=============================================================================

