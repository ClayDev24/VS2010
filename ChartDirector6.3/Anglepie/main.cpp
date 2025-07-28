#include <Windows.h> // ShellExecute():
#include "anglePie.h"
//#include "utils.h"

int main(int argc, char *argv[]) {
    chart::_anglePie(0, "anglepie0.png");
    chart::_anglePie(1, "anglepie1.png");
	ShellExecute(NULL, "open", "anglepie0.png", NULL, NULL, SW_SHOWDEFAULT);
	ShellExecute(NULL, "open", "anglepie1.png", NULL, NULL, SW_SHOWDEFAULT);

	system("pause");
    return(0);
}

