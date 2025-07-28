#pragma once
#include "instrument.h"

class Percussion : public Instrument {
public:
	inline void play(note nota) const {
		std::cout << "Percussion.";
		switch(nota) { // just accept integer types at compile-time.
		case  middleC:
			std::cout << "middleC playing...\n";
			break;
		case Csharp:
			std::cout << "Csharp playing...\n";
			break;
		case Cflat:
			std::cout << "Cflat playing...\n";
			break;
		default: std::cout << "Error, note not defined yet...";
		}
	};
	inline char* what() const { return "Percussion"; }
	inline void adjust(int) {} // Must be defined in the derived class
};