#ifndef _FRAMEWORK_
#define _FRAMEWORK_
#include "component.h"
#include "frame.h"
#include "button.h"

namespace clb {

	class Framework {
	private:
		vetorComponents       components;
		vetorFunctionPointers functions;
		//Graphical *window;
		Frame *mainFrame;

		Button *b1;
		Button *b2;
	protected:
	public:
		Graphical *window;
		//Framework() {};
		Framework(char *Label, const int &Right, const int &Botton, const WORD &Colour);
		~Framework() {
			delete window;
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
	};

}

#endif // _FRAMEWORK_