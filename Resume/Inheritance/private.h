// Private Inheritance
#pragma once

class Pet {
	
public:
	char  eat()   const { return 'a'; }
	int   speak()  const { return  2;  }
	float sleep()   const { return 3.0; }
	float sleep(int) const { return 4.0; }
};

// Private inheritance is useful if you want to hide part of the functionality of the base class:
class Goldfish:private Pet {
public:
	Goldfish() {
		int i = speak();
	}
	using Pet::eat;   // Name publicizes member
	using Pet::sleep; // Both members exposed
};