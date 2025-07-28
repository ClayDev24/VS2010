#include "framework.h"
#include "actions.h"
#define ver     "1.0"
#define prgdate "25/11/19"
#define author  "Written by claybom"
using namespace std;

//extern int keyCode;
int keyCode;

struct myFileData{
	char name[49];
	char name2[13];
} files[50];

int maxFiles=0;
int fileListScroll, fileListSelect;
int lineListScroll, lineListSelect;

//*****************************************************************************
clb::Framework::Framework(char *_label, const int &_x2, const int &_y2, const WORD &_cor) {
	wnd = new Graphical(_x2, _y2, _label);
	wnd->fillConsole(_cor,' ', 0, 0);

	b1     = new Button("Prev Line", 54, 16, 65, 18, BBI); // Column / Line
	b2     = new Button("Next Line", 66, 16, 77, 18, BBI);

	b3     = new Button("Prev File", 54, 19, 65, 21, BBI); // Column / Line
	b4     = new Button("Next File", 66, 19, 77, 21, BRI);

	b5     = new Button("Rand Line", 54, 22, 65, 24, BBI); // Column / Line
	b6     = new Button("Rand File", 66, 22, 77, 24, BRI);

	addComponent(b1);
	addComponent(b2);
	addComponent(b3);
	addComponent(b4);
	addComponent(b5);
	addComponent(b6);

	addAction(button1OnClick);
	addAction(button2OnClick);
	addAction(button3OnClick);
	addAction(button4OnClick);
	addAction(button5OnClick);
	addAction(button6OnClick);

	//b1.paint();
	//getReady();
	//initProgram();
	keyCode = 0;
	while(keyCode!=27)
		ReadConsoleKeyboardMouseInput();
}
//*****************************************************************************
void clb::Framework::addComponent(Component *_c) {
	components.push_back(_c);
}
//*****************************************************************************
void clb::Framework::addAction(functionPointer _f) {
	functions.push_back(_f);
}
//*****************************************************************************
void clb::Framework::paint() {
	// yet to be implemented...
}
//*****************************************************************************
void clb::Framework::ReadConsoleKeyboardMouseInput() {
	int mouseX=0, mouseY= 0, buttonState=0;
	INPUT_RECORD input_record;
	DWORD events;
	ReadConsoleInput(wnd->GetHandleIn(), &input_record, 1, &events);
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
				int left   = c->left;
				int top    = c->top;
				int right  = c->right;
				int bottom = c->bottom;
				char *label = c->m_label;

				if((mouseX>=left) && (mouseX<=right) && (mouseY>=top) && (mouseY<=bottom))
					functions[i](wnd, components[i]); // Derefering a function pointer from a vector.			
			} // for
			return;
		}
	}
}

void clb::Framework::initProgram() {
	getFiles();
	/*	createRandomFiles();

	JokeFile=doneFiles[0];
	JokeLine=doneLines[0];
	loadFile(files[JokeFile].name);
	createRandomLines();

	clrbox(1,2,79,15,31);

	selectFile();
	selectLine();
	putFilesList();
	putLinesList();
	displayJokeLine();
	*/
}

//*********************************************
void clb::Framework::getFiles(void) {
	WIN32_FIND_DATA fd;
	char pszSearchName[] = "jokes\\*.txt";
	int i=0;

	HANDLE hSearch = FindFirstFile(pszSearchName, &fd);

	if(hSearch != INVALID_HANDLE_VALUE) {
		do {
			strcpy_s(files[i].name,  "jokes\\");
			strcat_s(files[i].name,  fd.cFileName);
			strcpy_s(files[i++].name2, fd.cFileName);
		} while(FindNextFile(hSearch, &fd));
		FindClose(hSearch);
	} else
		cout<<" Error = INVALID_HANDLE_VALUE , No Joke files  found \n";
	maxFiles = i;
	//P_(maxFiles)
}
//*********************************************

void clb::Framework::FileScrollUp() {
	if(fileListScroll>7)
		fileListScroll--;
	else {
		fileListSelect--;
		if(fileListSelect<1)
			fileListSelect=0;
		fileListScroll=0;
	}
}
//*********************************************
void clb::Framework::FileScrollDown() {
	if(fileListSelect<7)
		fileListSelect++;
	else
		if ((fileListSelect+fileListScroll)<maxFiles-1)
			fileListScroll++;
}
//*********************************************
void clb::Framework::LineScrollDown() {
//	if(lineListSelect<7) lineListSelect++;
//	else
//		if ((lineListSelect+lineListScroll)<maxLines-1)
//			lineListScroll++;
}
//*********************************************
void clb::Framework::LineScrollUp() {
	if(lineListScroll>7)
		lineListScroll--;
	else {
		lineListSelect--;
		if(lineListSelect<1)
			lineListSelect=0;
		lineListScroll=0;
	}

}
//*********************************************
void clb::Framework::selectFile() {
//	fileListSelect=JokeFile;
	if (fileListSelect>6) {
		fileListSelect=7;
//		fileListScroll=JokeFile-7;
	}
}
//*********************************************
void clb::Framework::selectLine() {
//	lineListSelect=JokeLine;
	if(lineListSelect>6) {
		lineListSelect=7;
//		lineListScroll=JokeLine-7;
	}
}
//*********************************************
void clb::Framework::fileSelected() {
	putFilesList();
//	JokeFile=fileListSelect+fileListScroll;
//	loadFile(files[JokeFile].name);
	putLinesList();
	updateStatus();
	displayJokeLine();
}
void clb::Framework::lineSelected() {
	putLinesList();
//	JokeLine=lineListSelect+lineListScroll;
	displayJokeLine();
	updateStatus();
}
//*********************************************
void clb::Framework::updateStatus() {
	//clrbox(1,16,22,24,31);
	wnd->gotoxy(1,16);
	printf("Files  = %02i", maxFiles);
	wnd->gotoxy(1,17);
	//printf("File   = %02i of %02i",JokeFile+1,maxFiles);
	wnd->gotoxy(1,18);
	//printf("Unread = %02i ",unreadFiles);
	wnd->gotoxy(1,19);
	//printf("%s",files[JokeFile].name2);
	wnd->gotoxy(1,20);
	//printf("Lines  = %02i",maxLines);
	wnd->gotoxy(1,21);
	//printf("Line   = %02i of %02i",JokeLine+1,maxLines);
	wnd->gotoxy(1,22);
	//printf("Unread = %02i ",unreadLines);
	wnd->gotoxy(1,23);
	//printf("TimeDelay = %02i",TimeDelay);
}
//*********************************************
void clb::Framework::putFilesList() {
	//clrbox(24,16,42,24,31);
	//clrbox(39,16,42,24,224);

	//clrbox(39,16,42,17,240);
	wnd->gotoxy(40,16);
	//printf("<");

	//clrbox(39,23,42,24,240);
	wnd->gotoxy(40,23);
	printf(">");
	wnd->setColour(31);

	for(int i=0; i<8; i++) {
		wnd->gotoxy(24,16+i);
		printf(files[i+fileListScroll].name2);
	}

	wnd->setColour(240);
	wnd->gotoxy(24, 16+fileListSelect);
	printf(files[fileListSelect+fileListScroll].name2);
	wnd->setColour(31);
	//JokeFile=currentFile;
	updateStatus();
}
//*********************************************
void clb::Framework::putLinesList() {
	//clrbox(44,16,52,24,31);
	//clrbox(49,16,52,24,224);

	//clrbox(49,16,52,17,241);
	wnd->gotoxy(50,16);
	printf("<");

	//clrbox(49,23,52,24,241);
	wnd->gotoxy(50,23);
	printf(">");
	wnd->setColour(31);

	for(int i=0; i<8; i++) {
		wnd->gotoxy(46,16+i);
		printf("%02i", (i+lineListScroll)+1);
	}

	wnd->setColour(240);
	wnd->gotoxy(46,16+lineListSelect);
	printf("%02i",(lineListSelect+lineListScroll)+1);
	wnd->setColour(31);
}
//*********************************************
void clb::Framework::createRandomFiles() {
	for(int i=0; i<maxFiles; i++) {
		//doneFiles[i]=rand() % maxFiles;
		//for(int j=0; j<i; j++)
			//if(doneFiles[j]==doneFiles[i])
			//	i--;
	}
}
//*********************************************
void clb::Framework::createRandomLines() {
	//for(int i=0; i<maxLines; i++) {
		//doneLines[i]=rand() % maxLines;
		//for(int j=0; j<i; j++)
			//if(doneLines[j]==doneLines[i])
				//i--;
	//}
}
//*********************************************
void clb::Framework::loadFile(char *_file) {
/*	char buffer[256];
	ifstream in;

	for(int i=0; i<200; i++)
		for(int j=0; j<1024; j++)
			line[i][j] = ' ';

	unreadLines=0;
	in.open(_file);
	in.getline(JokeTitle,40);

	clrbox(0,2,80,15,0);
	clrbox(1,1,79,2,224);
	gotoxy(2,1);
	printf("Random Jokes:");
	setcolor(224);
	gotoxy(25,1);
	printf("%s        ", JokeTitle);
	clrbox(1,2,79,15,31);

	if(!in.is_open()) {
		cout << "Error opening file";
		exit(1);
	}
	int i=0;
	while(!in.eof()) {
		in.getline(buffer, 255);
		strcpy_s(line[i++], buffer);
	}
	maxLines=i;
	createRandomLines();
	in.close();
	*/
}
//*********************************************
void clb::Framework::displayJokeLine() {
	int pos = 0, x = 0, y = 0;

	//clrbox(1,2,79,15,31);
	wnd->setColour(31);
	/*while((line[JokeLine][pos]!='\0') &&(pos<700)) {
		gotoxy(x+2,y+3);
		printf("%c",line[JokeLine][pos]);
		pos++;
		x++;
		if ((x>65) && (line[JokeLine][pos]==' ')) {
			x=0 ;
			y++;
		}
	}*/
}
