#include "conio.h"
#include "framework.h"
//#include "frame.h"
//#include "button.h"
#include "panel.h"
#include "actions.h"
using namespace std;

extern int keyCode;
//*****************************************************************************
utils::Framework::Framework(char *_label, const int &_x2, const int &_y2, const WORD &_cor) {

	window = new Graphical(_x2, _y2, _label);
	window->setBufferSize(95, 40);
	window->fillConsole(_cor,' ', 0, 0);
	mainFrame = new Frame(*window, _x2-1, _y2-1);

	for(int p=0; p<1; p++) {
		for(int b=0; b<4; b++) {
			addComponent(mainFrame->panels[p]->buttons[b]);
		}
	}
	//b1 = new Button("Button1", 10, 10, BR);
	//b2 = new Button("Button2", 30, 10, BR);
	//addComponent(b1);
	//addComponent(b2);
	
	addAction(button1OnClick);
	addAction(button2OnClick);
	addAction(button3OnClick);
	addAction(button4OnClick);

	window->gotoxy(0, 0);
	//paint();
	//initProgram();
	keyCode = 0;
	while(keyCode!=27)
		ReadConsoleKeyboardMouseInput();
}
//*****************************************************************************
void utils::Framework::addComponent(Component *_c) {
	components.push_back(_c);
}
//*****************************************************************************
void utils::Framework::addAction(functionPointer _f) {
	functions.push_back(_f);
}
//*****************************************************************************
void utils::Framework::paint() {
	mainFrame->paint();
	//b1->paint();
	//b2->paint();
}
//*****************************************************************************
void utils::Framework::ReadConsoleKeyboardMouseInput() {
	int mouseX=0, mouseY= 0, buttonState=0;
	INPUT_RECORD input_record;
	DWORD events;
	ReadConsoleInput(window->GetHandleIn(), &input_record, 1, &events);
	mouseX      = input_record.Event.MouseEvent.dwMousePosition.X;
	mouseY      = input_record.Event.MouseEvent.dwMousePosition.Y;
	buttonState = input_record.Event.MouseEvent.dwButtonState;
	keyCode     = input_record.Event.KeyEvent.wVirtualKeyCode;
	//P_(components.size())
	if(input_record.EventType == MOUSE_EVENT) {
		if(buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			mouseX = input_record.Event.MouseEvent.dwMousePosition.X;
			mouseY = input_record.Event.MouseEvent.dwMousePosition.Y;
			for(unsigned int i=0; i<components.size(); i++) {
				Component   *c = components[i];
				int left   = c->m_left;
				int top    = c->m_top;
				int right  = c->m_right;
				int bottom = c->m_bottom;
				char *label = c->m_label;

				if((mouseX>=left) && (mouseX<=right) && (mouseY>=top) && (mouseY<=bottom))
					functions[i](window, components[i]); // Derefering a function pointer from a vector.
			} // for
			return;
		}
	}
}