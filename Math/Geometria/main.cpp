//#include "vld.h" // No memory leaks DETECTED!
#include "calculos.h"
#include "Shape.h"

int main() {
	using namespace std;

	utils::PrintColour_("<<_GEOMETRY_>>", FRI);

	_calculos();
	math::Shape s;
	s.show();

	system("pause");
	return(0);
}