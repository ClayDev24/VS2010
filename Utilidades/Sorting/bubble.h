#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "..\..\Utilidades\Utilidades\_showVetor.h"
#include "..\..\Utilidades\Utilidades\_random.h"
#include "..\..\Utilidades\Utilidades\_randomWords.h"

namespace utils {

    template<typename T>
    class BubbleSort {
    public:
        static void sort(std::vector<T>& arr) {
            int n = arr.size();
            bool swapped;

            for (int i = 0; i < n - 1; ++i) {
                swapped = false;

                // Last i elements are already in place
                for (int j = 0; j < n - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                // If no two elements were swapped in the inner loop, then the array is already sorted
                if (!swapped)
                    break;
            }
        }
    };

	// ***************** <<_USAGE_>> *****************
	template <typename T>
	static void _showSorting(std::vector<T> &vt, const std::string &msg) {
		std::cout << msg;
		utils::_showVetor(vt);

	}

	void bubbleSortUsage() {
		std::vector<std::string>		vs;
		std::vector<char>				vc;
		std::vector<int>				vi;
		std::vector<unsigned long>		vl;
		std::vector<unsigned long long>	vll;
		std::vector<float>				vf;
		std::vector<double>				vd;
		std::vector<long double>		vld;

		for(int i=0; i<100; i++) {
			int num    = utils::_random(0,100);
			std::string str = utils::_randomWords(6, 'a', 'z');
			vs.push_back((std::string)str);
			vc.push_back((char)num);
			vi.push_back(num);
			vf.push_back((float)num/2);
			vd.push_back((double)num/3);
			unsigned long num2 = utils::_random64(1, 4294967295);
			vl.push_back((unsigned long)num2);
			unsigned long long num3 = utils::_random64(1, 18446744073709551615);
			vll.push_back((unsigned long long)num3);
		}

		std::string msg1("Original array:\n");
		std::string msg2("Sorted array:\n");

		std::cout << msg1;
		utils::_showVetor(vi);
		BubbleSort<int>::sort(vi);
		_showSorting<int>(vi, msg2);

		std::cout << msg1;
		utils::_showVetor(vc);
		BubbleSort<char>::sort(vc);
		_showSorting<char>(vc, msg2);

		std::cout << msg1;
		utils::_showVetor(vf);
		BubbleSort<float>::sort(vf);
		_showSorting<float>(vf, msg2);

		std::cout << msg1;
		utils::_showVetor(vd);
		BubbleSort<double>::sort(vd);
		_showSorting<double>(vd, msg2);

		std::cout << msg1;
		utils::_showVetor(vl);
		BubbleSort<unsigned long>::sort(vl);
		_showSorting<unsigned long>(vl, msg2);

		std::cout << msg1;
		utils::_showVetor(vll);
		BubbleSort<unsigned long long>::sort(vll);
		_showSorting<unsigned long long>(vll, msg2);

		std::cout << msg1;
		utils::_showVetor(vs);
		BubbleSort<std::string>::sort(vs);
		_showSorting<std::string>(vs, msg2);

		// DOUBLE:
		//std::vector<double> dbl;
		//dbl.push_back(10.33);	

		//std::cout << "Original array:\n";
		//utils::_showVetor(dbl);

		//BubbleSort<double>::sort(dbl);

		//std::cout << "Sorted array:\n";
		//utils::_showVetor(dbl);
	}
}