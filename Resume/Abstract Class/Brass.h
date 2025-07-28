#pragma once
#include "wind.h"

class Brass : public Wind {
public:
	inline void play(note) const {
		std::cout << "Brass::play\n";
		// Usin' base class pure virtual function instead:
		//Wind::play(middleC);
	}
	inline char* what() const { return "Brass"; }
	inline void adjust(int) {}
};