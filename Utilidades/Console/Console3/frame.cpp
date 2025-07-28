#include <conio.h> // _getche()
#include "frame.h"
using namespace std;

//*****************************************************************************
clb::Frame::Frame():Component() {
	for(int i=0; i<MAXPANELS; i++) 
		panels[i] = NULL;
	DS_("Frame()...")
}
//*****************************************************************************
clb::Frame::Frame(Console &cmd, const int &_x2, const int &_y2):Component("Frame", 0, 0, _x2, _y2, BGI) {
	int left, right, top, bottom;
	cmd.boundaries(right, bottom);
	left = 0, top = 0;
	vetorString *vStr;
	vStr = new vetorString();
	
	for(int i=0; i<MAXPANELS; i++) 
		panels[i] = NULL;
	//panels[] = new Panel("Menu", left, top, right, 2, BRI);
	panels[TOP]    = new Panel(TOP,    "Top Panel",    left, top, right, 2, BRI);
	panels[BOTTOM] = new Panel(BOTTOM, "Bottom Panel", left, bottom-2, right, bottom, BRI);
	panels[LEFT]   = new Panel(LEFT,   "Left Panel",   left, panels[0]->m_bottom+1, left+10, panels[1]->m_top-1, BY);
	panels[RIGHT]  = new Panel(RIGHT,  "Right Panel",  right-10, panels[0]->m_bottom+1, right, panels[1]->m_top-1, BYI);
	panels[CENTRAL]= new Panel(CENTRAL,"Central panel",left, top, right, 2, BRI);
	vStr->push_back("Button1");
	vStr->push_back("Button2");
	vStr->push_back("Button3");
	vStr->push_back("Button4");
	//vStr->push_back("Button5");

	panels[TOP]->createComponent(*vStr, BUTTON);

	gotoxy(0, 0);
	//paint();
	//P_(right)
	//P_(bottom)
	//_getche();
	DS_("Frame(Console &cmd)...")
}