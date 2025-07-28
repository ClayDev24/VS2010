#include <iostream>  
#include <cmath>
#include <iomanip>
#include <limits>           // Para ter a máxima precisão

namespace clb {

	static void _doublePrecision() {
		using namespace std;
		double d1=2.0;
		//cout << setprecision(numeric_limits<double>::max_digits) << sqrt(d1) << endl;

		double d2 = sqrt(2.0);
		cout << fixed;
		cout.precision(52);
		cout << d2 << endl;

		float pi = static_cast<float>(3.14);
		double piDouble = 3.1415926535897932384626433832795;
		cout << setprecision(numeric_limits<double>::max_digits10) << piDouble << endl;
		cout << fixed;
		cout.precision(52);
		cout << piDouble << endl;

		std::cout << "type\tlowest()\tmin()\t\tmax()\n\n"
			<< "bool\t"
			<< std::numeric_limits<bool>::lowest() << "\t\t"
			<< std::numeric_limits<bool>::min() << "\t\t"
			<< std::numeric_limits<bool>::max() << '\n'
			<< "uchar\t"
			<< +std::numeric_limits<unsigned char>::lowest() << "\t\t"
			<< +std::numeric_limits<unsigned char>::min() << "\t\t"
			<< +std::numeric_limits<unsigned char>::max() << '\n'
			<< "int\t"
			<< std::numeric_limits<int>::lowest() << '\t'
			<< std::numeric_limits<int>::min() << '\t'
			<< std::numeric_limits<int>::max() << '\n'
			<< "long\t"
			<< std::numeric_limits<unsigned long>::lowest() << '\t'
			<< std::numeric_limits<unsigned long>::min() << '\t'
			<< std::numeric_limits<unsigned long>::max() << '\n'
			<< "float\t"
			<< std::numeric_limits<float>::lowest() << '\t'
			<< std::numeric_limits<float>::min() << '\t'
			<< std::numeric_limits<float>::max() << '\n'
			<< "double\t"
			<< std::numeric_limits<double>::lowest() << '\t'
			<< std::numeric_limits<double>::min() << '\t'
			<< std::numeric_limits<double>::max() << '\n';
	}
}