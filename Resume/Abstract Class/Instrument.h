// Pure abstract base classes
#pragma once

enum note { middleC, Csharp, Cflat }; // Same as assining names to ints

class Instrument { // Pure Abstract Class: All member functions are pure virtual:
	int m_i;
public:
	// Pure virtual functions:
	virtual void  play(note) const = 0; // const functions cannot modify objs.
	virtual char* what()     const = 0;
	// Assume this will modify the object:
	virtual void  adjust(int)      = 0;
};
