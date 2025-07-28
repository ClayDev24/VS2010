#pragma once
#include <iostream>
#include <vector>
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace utils {

    template<typename T>
    class SelectionSort {
    public:
        static void sort(std::vector<T>& arr) {
            int n = arr.size();
            for (int i = 0; i < n - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < n; ++j) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    std::swap(arr[i], arr[minIndex]);
                }
            }
        }
    };

	// ***************** <<_USAGE_>> *****************
	void selectionSortUsage() {
		std::vector<int> arr;
		arr.push_back(10);	
		arr.push_back(7);	
		arr.push_back(8);	
		arr.push_back(9);	
		arr.push_back(1);	
		arr.push_back(5);	

		std::cout << "Original array:\n";
		utils::_showVetor(arr);

		SelectionSort<int>::sort(arr);

		std::cout << "Sorted array:\n";
		utils::_showVetor(arr);


		// DOUBLE:
		std::vector<double> dbl;
		dbl.push_back(10.33);	
		dbl.push_back(7.67);	
		dbl.push_back(8.0);	
		dbl.push_back(9.5);	
		dbl.push_back(9.6);	
		dbl.push_back(5.0);	

		std::cout << "Original array:\n";
		utils::_showVetor(dbl);

		SelectionSort<double>::sort(dbl);

		std::cout << "Sorted array:\n";
		utils::_showVetor(dbl);
	}
}