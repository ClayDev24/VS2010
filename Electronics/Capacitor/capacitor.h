#pragma once
#include <new>		// std::nothrow
#include <Windows.h> // ShellExecute();
#include "utils.h"
#include "..\..\include\ChartDirector63\chartdir.h"
#include "I:\Programming\CPP\VS2010\ChartDirector6.3\simpleLine\simpleLine.h"

static double toleranceTABLE[19][19][19] = {
	'A',   0.05, 'p',
	'B',   0.1,  'p',
	'C',   0.25, 'p',
	'D',   0.5,  'p',
	'E',   0.5,  'p',
	'F',   1.0,  '%',
	'G',   2.0,  '%',
	'H',   3.0,  '%',
	'J',   5.0,  '%',
	'K',  10.0,  '%',
	'L',  15.0,  '%',
	'M',  20.0,  '%',
	'N',  30.0,  '%',
	'P',   0.0, 100.0,
	'S', -20.0,  50.0, // No less than, as much as
	'W',   0.0, 200.0,
	'X', -20.0,  40.0,
	'Z', -20.0,  80.0,
	0.0,   0.0,   0.0 /* nulo termina a lista */
};

namespace elect {

	class CCapacitor {
		int  *pValue;
		float m_capacitance;
		float m_voltage; // working voltage
		float m_tolerance;
		int   m_size, m_val1, m_val2, m_multiplier;
	public:
		CCapacitor(int &_Value, int sz);
		CCapacitor(float capacitance):m_capacitance(capacitance) {}
		~CCapacitor() {
			if(pValue)
				delete[] pValue;
			DS_("~CCapacitor().../")
		}
		void print();
		void tolerance(float t);
	};
	// **************<<_USAGE_>>****************
	static double timeConstant(double Resistance, double Capacitance) {
		// T = R x C (Time Constant = Resistance (Ohms) x Capacitance (Farads)
		return Resistance * Capacitance;
	}
	static void fullChargeGraph(double VBat) {
		double VDif = 0.0;	// The difference between VBaterry and VCap (the remaining unfilled capacitance)
		double VCap = 0.0;	// The voltage on capacitor in each stage of time constant:
		double VSum = 0.0;
		int sz = 8;
		const char *labels[9] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"}; // The labels for the line chart
		double* m_plot = new(std::nothrow) double[sz];
		for(int i=0; i<sz; i++) {
			// The data for the line chart
			m_plot[i] = VSum;

			VDif = VBat - VSum; // O restante
			VSum += VCap = (0.63 * VDif);
			//P_(VCap)
			P_(VSum)
		}
		chart::_simpleLine(m_plot, labels, sz, 500, 500, true);
	}
	static void capacitorUsage() {
		P_(timeConstant(1000, 0.00001))
		fullChargeGraph(10);
	}

} // elect