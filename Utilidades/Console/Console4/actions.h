#ifndef _ACTIONS_
#define _ACTIONS_
#include "graphical.h"
#include "button.h"

namespace clb {

	void button1OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
		_c->paint();

		/*
		clrbox(54,16,65,18,15);
		_wnd->gotoxy(55,17);
		printf("Prev Line");
		Sleep(20);
		clrbox(54,16,65,18,224);
		_wnd->gotoxy(55,17);
		printf("Prev Line");

		LineScrollUp();
		currentLine=lineListSelect+lineListScroll;
		unreadLines=maxLines-currentLine;
		lineSelected();
*/
	}

	void button2OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);

		/*clrbox(66,16,77,18,15);
		gotoxy(67,17);
		printf("Next Line");
		Sleep(20);
		clrbox(66,16,77,18,224);
		gotoxy(67,17);
		printf("Next Line");
		LineScrollDown();
		currentLine=lineListSelect+lineListScroll;
		unreadLines=maxLines-currentLine;
		lineSelected();*/
	}

	void button3OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);

		//clrbox(54,19,65,21,15);
		//_wnd->gotoxy(55,20);
		//printf("Prev File");
		//Sleep(200);
		//clrbox(54,19,65,21,31);
		//_wnd->gotoxy(55,20);
		//printf("Prev File");

		//FileScrollUp();
		//fileSelected();
	}
	void button4OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);
		
		//clrbox(66,19,77,21,15);
		//_wnd->gotoxy(67,20);
		//printf("Next File");
		//Sleep(20);
		//clrbox(66,19,77,21,31);
		//_wnd->gotoxy(67,20);
		//printf("Next File");

		//FileScrollDown();
		//fileSelected();
	}

	void button5OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);

		//clrbox(54,22,65,24,15);
		//_wnd->gotoxy(55,23);
		//printf("Rand Line");
		//Sleep(20);
		//clrbox(54,22,65,24,79);
		//_wnd->gotoxy(55,23);
		//printf("Rand Line");

		//currentLine++;
		//JokeLine=doneLines[currentLine];
		////JokeLine=currentLine;
		//unreadLines=maxLines-currentLine;
		//selectLine();
		//lineSelected();
	}
	void button6OnClick(Graphical *_wnd, Component *_c) {
		_wnd->gotoxy(0,0);
		_wnd->write2Console(_c->m_label);

		//clrbox(66,22,77,24,15);
		//_wnd->gotoxy(67,23);
		//printf("Rand File");
		//Sleep(20);
		//clrbox(66,22,77,24,79);
		//_wnd->gotoxy(67,23);
		//printf("Rand File");
		////linearMode=-linearMode;
		//lineListScroll=0;
		//lineListSelect=0;
		//currentFile++;
		//JokeFile=doneFiles[currentFile];
		//unreadFiles=maxFiles-currentFile;
		//selectFile();
		//fileSelected();
		//if(currentFile>maxFiles) {
		//	currentFile=-1;
		//	fileListScroll=0;
		//	fileListSelect=0;
		//}
	}

/*
	void button2OnClick(Graphical *_wnd, Component *_c) {
			
			if (currentLine>maxLines) {
			currentFile++;
			JokeFile=doneFiles[currentFile];
			unreadFiles=maxFiles-currentFile;
			selectFile();
			putFilesList();

			maxLines=0;
			loadFile(files[JokeFile].name);
			//createRandomLines();
			lineListScroll=0;
			lineListSelect=0;
			currentLine=0;
			currentLine++;
			JokeLine=doneLines[currentLine];
			unreadLines=maxLines-currentLine;
			selectLine();
			lineSelected();
		}
	void button3OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>38) && (mouseX<42) && (mouseY==16)) {
		FileScrollUp();
		currentFile = fileListSelect+fileListScroll;
		unreadFiles = maxFiles-currentFile;
		putFilesList();

		clrbox(39,16,42,17,15);
		gotoxy(40,16); printf("<");
		Sleep(20);
		clrbox(39,16,42,17,255);
		gotoxy(40,16); printf("<");
	}
	void button4OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>38) && (mouseX<42) && (mouseY==23)) {
		FileScrollDown();
		currentFile=fileListSelect+fileListScroll;
		unreadFiles=maxFiles-currentFile;
		putFilesList();

		clrbox(39,23,42,24,15);
		gotoxy(40,23);printf(">");
		Sleep(20);
		clrbox(39,23,42,24,240);
		gotoxy(40,23);printf(">");
	}
	void button5OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>23) && (mouseX<37) && (mouseY>15) && (mouseY<24)) {
		lineListScroll=0;
		lineListSelect=0;
		fileListSelect=(mouseY-16);//+fileListScroll;
		fileSelected();
	}
	void button6OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>48) && (mouseX<52) && (mouseY==16)) {
		LineScrollUp();
		clrbox(49,16,52,17,15);
		gotoxy(50,16);printf("<");
		Sleep(20);
		clrbox(49,16,52,17,241);
		gotoxy(50,16);printf("<");
		lineSelected();
	}
	void button7OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>48) && (mouseX<52) && (mouseY==23)) {
		LineScrollDown();
		clrbox(49,23,52,24,15);
		gotoxy(50,23);printf(">");
		Sleep(20);
		clrbox(49,23,52,24,241);
		gotoxy(50,23);printf(">");
		lineSelected();
	}
	void button8OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>43) && (mouseX<49) && (mouseY>15) && (mouseY<24)) {
		lineListSelect=(mouseY-16);
		lineSelected();
	}
	void button15OnClick(Graphical *_wnd, Component *_c) {
		//if((mouseX>1) && (mouseX<9) && (mouseY==0)) {
		setcolor(15);gotoxy(2,0);printf(" EXIT ");
		Sleep(50);
		setcolor(79);gotoxy(2,0);printf("EXIT  ");
		Sleep(50);
		setcolor(15);
		cls();
		exit(0);
	}
*/
}

#endif // _ACTIONS_