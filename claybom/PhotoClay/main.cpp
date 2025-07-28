//#include "vld.h"
#include "utils.h"
using namespace std;
using namespace utils;

void PhotoClay(int _x=80, int _y=50) { // Columns x Lines
	Console cmd(_x, _y, "PhotoClay");
	
    CHAR_INFO *consoleBuffer = new CHAR_INFO[_x * _y];
    // Set up the positions:
    COORD charBufSize    = {_x,_y};
    COORD characterPos   = {0,0};
    SMALL_RECT writeArea = {0,0,_x-1,_y-1};

	cmd.fillConsole(BWI|FWI);
    // How many events have happened?
    DWORD numEvents = 0;
    // How many events have we read from the console?
    DWORD numEventsRead = 0;
    // Boolean flag to state whether app is running or not.
    bool  running = true;
    while(running) {
        // Find out how many console events have happened:
        GetNumberOfConsoleInputEvents(cmd.GetHandleIn(), &numEvents);
        // If it's not zero (something happened...)
        if(numEvents != 0) {
            // Create a buffer of that size to store the events
            INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];
            // Read the console events into that buffer, and save how
            // many events have been read into numEventsRead.
            ReadConsoleInput(cmd.GetHandleIn(), eventBuffer, numEvents, &numEventsRead);
            // Now, cycle through all the events that have happened:
            for(DWORD i = 0; i < numEventsRead; ++i) {
                // Check the event type: was it a key?
                if(eventBuffer[i].EventType == KEY_EVENT) {
                    // Yes! Was the key code the escape key?
                    if(eventBuffer[i].Event.KeyEvent.wVirtualKeyCode==VK_ESCAPE) {
                        // Yes, it was, so set the appIsRunning to false.
						cmd.cursor(0,0);
                        running = false;
                    // Was if the 'c' key?
                    } else if(eventBuffer[i].Event.KeyEvent.uChar.AsciiChar=='c')
						cmd.fillConsole(BWI|FWI);
                   
                } else if(eventBuffer[i].EventType == MOUSE_EVENT) {
                    
                    // Set the index to our buffer of CHAR_INFO
                    int offsetPos =
                        eventBuffer[i].Event.MouseEvent.dwMousePosition.X 
                        + 80 * eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    // Is it a left click?
                    if(eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                        // Yep, so set with character 0xDB (solid block)
                        consoleBuffer[offsetPos].Char.AsciiChar = (char)0xDB;
                        // Redraw our buffer:
                        WriteConsoleOutputA(cmd.GetHandleOut(), consoleBuffer, charBufSize, characterPos, &writeArea);
                    // Is it a right click?
                    } else if (eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
                        // Yep, so set with character 0xB1 (50% block)
                        consoleBuffer[offsetPos].Char.AsciiChar = (char)0xB1;
                        // Redraw our buffer:
                        WriteConsoleOutputA(cmd.GetHandleOut(), consoleBuffer, charBufSize, characterPos, &writeArea);
                    // Is it a middle click?
                    } else if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_2ND_BUTTON_PRESSED) {
                        // Yep, so set with character space.
                        consoleBuffer[offsetPos].Char.AsciiChar = ' ';
                        // Redraw our buffer:
                        WriteConsoleOutputA(cmd.GetHandleOut(), consoleBuffer, charBufSize, characterPos, &writeArea);                        
                    }
                }
            }
            delete[] eventBuffer;
        }
    }
}

int main() {
	
	PhotoClay(80, 60);

	system("pause");
	return(0);
}