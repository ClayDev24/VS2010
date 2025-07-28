#include "Instrument.h"
//Pure Virtual Function Definition: A common piece o'code that you want some or all the derived class definitions 
// to call rather than duplicatin' that code in every function.
//void Instrument::play(note) const {
//	cout << "Instrument::play" << endl;
//}

void Instrument::adjust(int) {
	m_i = 0;
}
