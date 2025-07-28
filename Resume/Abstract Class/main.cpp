// #include "vld.h" // No memory leaks DETECTED!
#include <iostream> // cout, getchar()
#include "Instrument.h"
#include "Brass.h"
#include "Percussion.h"
#include "Stringed.h"
#include "Wind.h"
using namespace std;

// You create an abstract class when you only want to manipulate a set o'classes through a common interface:
void tune(Instrument& _i) {
	// ...
	_i.play(middleC);
}

// New function:
void adjust(Instrument& _i) { _i.adjust(1); }

int main() {
	//Instrument i1;     // ERROR. Cannot be created: Pure abstract class
	//Wind		 flaute; // ERROR. Cannot be created: Abstract class

	Percussion	drum;
	Stringed	violin;
	Brass		flugelhorn;

	tune(drum);
	tune(violin);
	tune(flugelhorn);
	adjust(flugelhorn);

	system("pause");
	return(0);
}
