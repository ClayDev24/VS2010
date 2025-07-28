// Inheritance & upcasting
#pragma once
enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
	inline void play(note) const {}
};

// Wind objects are Instruments (is-a relationship)
// 'cause they have the same interface:
class Wind : public Instrument {};

static void tune(Instrument& i) {
	// ...
	i.play(middleC);
}

static void _upcasting() {
	Wind flute;
	tune(flute); // Upcasting=> Treatin' a derived type as it was a base type.

	Wind w;
	Instrument* ip = &w; // Upcasting
	Instrument& ir = w;  // Upcasting
} 
