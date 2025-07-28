#pragma once
#include "utils.h"

namespace electro {

	class CLED {
		//int  *pValue;
		float m_colour;
		float m_forwardVoltage; // Depends on colour. Range from 1.5V to 4.6V
		float m_current;		// LEDs can carry currents of up to about 20mA. Increasing current will strengthens the light emitted by the led, as the drop voltage remais the same.
		//int   m_size;
	public:
		//00000CLED(int &_Value, int sz);
		CLED(float _colour):m_colour(_colour) {}
		~CLED() {
			DS_("~CLED().../")
		}
		void print();
	};
	// **************<<_USAGE_>>****************
	static void LEDUsage() {

	}

} // electro