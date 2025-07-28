#pragma once
#include <iostream>
#include <string>
#include "utils.h"

namespace elect {

	class CEserie {
		std::string m_label;
		double m_res;
		double m_tol;
		double m_Hi;
		double m_Low;
		double m_Hit;
		double *pTMP;
		int    m_Sz;

		void chooseSerie(const double &Tolerance);
		void makeESerie(const  double &Resistance, const double &Tolerance);
	public:
		CEserie():m_res(0.0), m_tol(40.0) { makeESerie(m_res, m_tol); }
		CEserie(double _res, double _tol):m_res(_res), m_tol(_tol) { makeESerie(m_res, m_tol); }
		double getHigher()  { return m_Hi;  }
		double getLower()   { return m_Low; }
		double getClose()   { return m_Hit; }
		double size() { return m_Sz;  }
		std::string getStr() {
			std::string s = "E" + utils::_toStr(m_Sz);
			return s;
		}
		void changeSerie(double _res, double _tol) { makeESerie(_res, _tol); }
		void displayAll(double Tolerance);
		int  comparisonSeries(double *A, double *B, int szA, int szB);
		int  scanningSeries(int Serie);
		double *getPtr() { return pTMP; }
	};
	// **************<<_USAGE_>>****************
	void ceserieUsage();

} // elect