#pragma once
#include <iostream>
#include <vector>
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace utils {

	template<typename T>
	class QuickSort2 {
	public:
		// Public function to sort a vector using Quicksort
		static void sort(std::vector<T>& arr) {
			quicksort(arr, 0, arr.size() - 1);
		}

	private:
		// Private function to partition the array and return the index of the pivot
		static int partition(std::vector<T>& arr, int low, int high) {
			T pivot = arr[high]; // Choose the last element as pivot
			int i = low - 1; // Index of the smaller element

			for (int j = low; j < high; j++) {
				if (arr[j] <= pivot) {
					i++;
					swap(arr[i], arr[j]);
				}
			}
			swap(arr[i + 1], arr[high]);
			return i + 1;
		}

		// Private function to perform Quicksort recursively
		static void quicksort(std::vector<T>& arr, int low, int high) {
			if (low < high) {
				int pi = partition(arr, low, high);
				quicksort(arr, low, pi - 1);
				quicksort(arr, pi + 1, high);
			}
		}

		// Private function to swap two elements in the array
		static void swap(T& a, T& b) {
			T temp = a;
			a = b;
			b = temp;
		}
	};

	// ***************** <<_USAGE_>> *****************
	void quickSortUsage() {
		std::vector<int> arr;
		arr.push_back(10);	
		arr.push_back(7);	
		arr.push_back(8);	
		arr.push_back(9);	
		arr.push_back(1);	
		arr.push_back(5);	

		std::cout << "Original array:\n";
		utils::_showVetor(arr);

		QuickSort2<int>::sort(arr);

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

		QuickSort2<double>::sort(dbl);

		std::cout << "Sorted array:\n";
		utils::_showVetor(dbl);
	}
}
