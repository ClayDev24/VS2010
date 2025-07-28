#pragma once
#include <algorithm>  // std::sort
#include <stdarg.h>   // va_list, va_start, va_arg, va_end
#include "typedefs.h"
#include "utils.h"

namespace math {

	// Function to calculate the least common multiple (LCM) of two numbers
	static unsigned int _LCM(unsigned int a, unsigned int b) {
		unsigned int num1 = a;
		unsigned int num2 = b;
		while (num1 != num2) {
			if (num1 < num2) {
				num1 += a;
			} else {
				num2 += b;
			}
		}
		return num1;
	}
// Function to calculate the least common multiple (LCM) of multiple numbers
	static unsigned long int _MultipleLCM(int count, ...) {
		std::vector<unsigned int> numbers;
		// Fulfilling vector numbers:
		va_list args;
		va_start(args, count);
		for(int i = 0; i < count; ++i)
			numbers.push_back(va_arg(args, unsigned int));
		va_end(args);

		std::sort(numbers.begin(), numbers.end());
		unsigned int result = numbers[0];
		for(int i = 1; i < count; ++i)
			result = _LCM(result, numbers[i]);

		return static_cast<unsigned long int>(result);
	}
	// Using Recursion: (mais lento que os anteriores)
	static unsigned long int _MMC(int _sz, ...) { REQUIRE(_sz >= 2) // STACK version (FASTER!)
		vetorUInt numbers;
		int count = _sz+1;
		// Fulfilling numbers:
		va_list args;
		va_start(args, _sz);
		while(--count)
			numbers.push_back(va_arg(args, unsigned int));
		va_end(args);
		// 
		sort(numbers.begin(), numbers.end());
		unsigned long int a = numbers[count++];
		unsigned long int b = numbers[count++];
		//while(true)
		for(int num1=2, num2=2; true;)
			if(a==b) {
				while((_sz--)-2) // is it the end?
					a = _MMC(2, numbers[count++], a); // Recursive call...
				return a;
			} else
				if(a<b) // se a menor multiplica a
					a = numbers[0] * num1++;
				else	// se b menor multiplica b
					b = numbers[1] * num2++;
	}

	// **************<<_USAGE_>>****************
	static void test();
	static void test2();
	static void _mmcUsage() { // { _mmcUsage 1 is on the Fatoracao.h

		//utils::dicShow("mathematics", "Mdc");
		utils::PrintColour_("\n<<_(M)ínimo_(M)últiplo_(C)omun_>>\n", BRI);

		//P_(utils::_chronometer(&test))
		//P_(utils::_chronometer(&test2))
				P_(_MMC(5,90,24,32,40,100))
		P_(_MultipleLCM(5,90,24,32,40,100))
	}

	void test() {
		//vetorUint vetor;
		for(int i=0; i<100; i++)
			_MMC(5, 390,424,532,640,7100);
	}
	
	void test2() {
		for(int i=0; i<1000; i++)
			_MultipleLCM(5, 390,424,532,640,7100);
	}

} // math