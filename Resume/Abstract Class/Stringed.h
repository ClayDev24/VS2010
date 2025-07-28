#pragma once
#include "instrument.h"

class Stringed : public Instrument {
public:
	inline void play(note) const {
		std::cout << "Stringed::play\n";
	}
	inline char* what() const { return "Stringed"; }
	inline void adjust(int) {} // Must be defined in the derived class
};