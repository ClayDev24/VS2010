#pragma once
#include <iostream>
#include <vector>
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace utils {

	template<typename T>
    class ShellSort {
    public:
        static void sort(std::vector<T>& arr) {
            int n = arr.size();

            // Start with a big gap, then reduce the gap
            for (int gap = n / 2; gap > 0; gap /= 2) {
                // Do a gapped insertion sort for this gap size.
                // The first gap elements arr[0..gap-1] are already in gapped order
                // keep adding one more element until the entire array is gap sorted
                for (int i = gap; i < n; ++i) {
                    // add arr[i] to the elements that have been gap sorted
                    // save arr[i] in temp and make a hole at position i
                    T temp = arr[i];

                    // shift earlier gap-sorted elements up until the correct location for arr[i] is found
                    int j;
                    for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                        arr[j] = arr[j - gap];

                    // put temp (the original arr[i]) in its correct location
                    arr[j] = temp;
                }
            }
        }
    };

	// ***************** <<_USAGE_>> *****************
	void shellSortUsage() {
		std::vector<int> arr;
		arr.push_back(10);	
		arr.push_back(7);	
		arr.push_back(8);	
		arr.push_back(9);	
		arr.push_back(1);	
		arr.push_back(5);	

		std::cout << "Original array:\n";
		utils::_showVetor(arr);

		ShellSort<int>::sort(arr);

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

		ShellSort<double>::sort(dbl);

		std::cout << "Sorted array:\n";
		utils::_showVetor(dbl);
	}
}