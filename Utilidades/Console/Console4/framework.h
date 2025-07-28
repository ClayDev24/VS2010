#ifndef _FRAMEWORK_
#define _FRAMEWORK_
#include <vector>
#include "component.h"
#include "button.h"
typedef std::vector<clb::Component*> vetorComponents;
typedef std::vector<clb::Component*>::iterator it;

typedef void (*functionPointer)(clb::Graphical*, clb::Component*);

typedef std::vector<functionPointer> vetorFunctionPointers;

namespace clb {

	class Framework {
	private:
		vetorComponents       components;
		vetorFunctionPointers functions;
		
		Button    *b1;
		Button    *b2;
		Button    *b3;
		Button    *b4;
		Button    *b5;
		Button    *b6;
	protected:
	public:
		Graphical *wnd;
		Framework() {};
		Framework(char *Label, const int &Right, const int &Botton, const WORD &Colour);
		~Framework(){
			delete wnd;
			for(unsigned int i=0; i<components.size(); i++)
				delete components[i];
			//delete b1;
			//delete b2;
		};
		void paint();
		void addComponent(Component *_c);
		void addAction(functionPointer _f);
		void ReadConsoleKeyboardMouseInput();
		void initProgram();
		void getFiles();

		void FileScrollUp();
		void FileScrollDown();
		void LineScrollDown();
		void LineScrollUp();
		void selectFile();
		void selectLine();
		void fileSelected();
		void lineSelected();
		void updateStatus();
		void putFilesList();
		void putLinesList();
		void createRandomFiles();
		void createRandomLines();
		void loadFile(char *_file);
		void displayJokeLine();
	};

}

#endif // _FRAMEWORK_