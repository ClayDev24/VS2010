// Extensibility in OOP
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
using namespace std;

enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
	virtual void play(note) const { // To dynamic (late) binding this function
		cout << "Instrument::play" << endl;
	}
	virtual char* what() const {
		return "Instrument";
	}
	// Assume this will modify the object:
	virtual void adjust(int) const {}
};

class Wind : public Instrument {
public:
	void play(note) const {
		cout << "Wind::play" << endl;
	}
	char* what() const { return "Wind"; }
	void adjust(int) {}
};

class Percussion : public Instrument {
public:
	void play(note) const {
		cout << "Percussion::play" << endl;
	}
	char* what() const { return "Percussion"; }
	void adjust(int) {}
};

class Stringed : public Instrument {
public:
	void play(note) const {
		cout << "Stringed::play" << endl;
	}
	char* what() const { return "Stringed"; }
	void adjust(int) {}
};

class Brass : public Wind {
public:
	void play(note) const {
		cout << "Brass::play" << endl;
	}
	char* what() const { return "Brass"; }
};

class Woodwind : public Wind {
public:
	void play(note) const {
		cout << "Woodwind::play" << endl;
	}
	char* what() const { return "Woodwind"; }
};

// Identical function from before:
static void tune(const Instrument& i) {
	// ...
	i.play(middleC);
}

static void tune2(const Wind& w) {
	// ...
	w.play(middleC);
}

// New function:
static void adjust(Instrument& _i) {
	_i.adjust(1);
}

class NoVirtual {
	int a;
public:
	inline void x() const {}
	inline int i() const { return 1; }
};

class OneVirtual {
	int a;
public:
	inline virtual void x() const {}
	inline int i() const { return 1; }
};

class TwoVirtuals {
	int a;
public:
	inline virtual void x() const {}
	inline virtual int  i() const { return 1; }
};

int main() {
	cout << "int: " << sizeof(int) << endl;
	cout << "NoVirtual: "
		<< sizeof(NoVirtual) << endl;
	cout << "void* : " << sizeof(void*) << endl;
	cout << "OneVirtual: "
		<< sizeof(OneVirtual) << endl;
	cout << "TwoVirtuals: "
		<< sizeof(TwoVirtuals) << endl;

	Wind		flute;
	Percussion	drum;
	Stringed	violin;
	Brass		flugelhorn;
	Woodwind	recorder;
	tune(flute);
	tune(drum);
	tune(violin);
	tune2(flugelhorn);
	tune(recorder);
	adjust(flugelhorn);

	// Upcasting to Instrument during array initialization:
	Instrument *instruments[] = {
		new Wind,
		new Percussion,
		new Stringed,
		new Brass,
	};
	delete instruments[0];
	delete instruments[1];
	delete instruments[2];
	delete instruments[3];

	system("pause");
	return(0);
}
