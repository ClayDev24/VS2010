#pragma once
#include <iostream>
#include <vector>
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace utils {
	template<typename T>
	class InsertionSort {
	public:
		static void sort(std::vector<T>& arr) {
			int n = arr.size();
			for (int i = 1; i < n; ++i) {
				T key = arr[i];
				int j = i - 1;

				// Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
				while (j >= 0 && arr[j] > key) {
					arr[j + 1] = arr[j];
					--j;
				}
				arr[j + 1] = key;
			}
		}
	};

	// ***************** <<_USAGE_>> *****************
	void insertionSortUsage() {
		std::vector<int> arr;
		arr.push_back(10);	
		arr.push_back(7);	
		arr.push_back(8);	
		arr.push_back(9);	
		arr.push_back(1);	
		arr.push_back(5);	

		std::cout << "Original array:\n";
		utils::_showVetor(arr);

		InsertionSort<int>::sort(arr);

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

		InsertionSort<double>::sort(dbl);

		std::cout << "Sorted array:\n";
		utils::_showVetor(dbl);
	}
}