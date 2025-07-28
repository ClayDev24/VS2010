#include <iostream>
#include "SDL\SDL.h"
//*************<<_INSTALL SDL GUIDELINES_>>**********************************************************************
// Visual Studio 2010
// Create empty project
// Property page (alt+f7)
// Active Desktop=> All Configurations
// Configuration Properties=>VC++Directories
// -Include Directories=> $(INCLUDE_DIR) 
// -Library Directories=> $(LIB_DIR)

// -C/C++=>Code Generation=> RunTime Library=> Multi threaded DLL (/MD)
// -C/C++=>Precompiled Headers=> Precompiled Header=> Not Using Precompiled Headers
// -Linker=>Input=>Additional Dependencies=> SDL2.lib; SDL2main.lib
// -Linker=>System=>SubSystem=> Windows (/SUBSYSTEM:WINDOWS)

// Copy SDL.dll to C:\WINDOWS\SYSTEM32 so your SDL app will find SDL.dll even if it's not in the same directory.
// If you're using a 64bit version of Windows, you'll want to put the dll in C:\Windows\SysWOW64.
//***************************************************************************************************************
int main(int argc, char* args[]) {
    //Start SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    
    //Quit SDL
    SDL_Quit();
    
	system("pause");
    return(0);
}