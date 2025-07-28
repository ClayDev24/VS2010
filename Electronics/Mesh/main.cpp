#include <iostream>
#include "Mesh.h"
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();	//habilita a acentuação para o português
	TAB TAB
	utils::Console cmd(80, 30, "<<_MESH_>>");
	utils::PrintColour_("<<_MESH_>>\n", FRI);

	elect::_meshUsage();

	system("pause");
	return(0);
}