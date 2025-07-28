#pragma once
#include <iostream>
#include <vector>
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace utils {

    template<typename T>
    class MergeSort {
    public:
        static void sort(std::vector<T>& arr) {
            mergesort(arr, 0, arr.size() - 1);
        }

    private:
        static void merge(std::vector<T>& arr, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            std::vector<T> L(n1), R(n2);

            for (int i = 0; i < n1; ++i)
                L[i] = arr[left + i];
            for (int j = 0; j < n2; ++j)
                R[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    ++i;
                } else {
                    arr[k] = R[j];
                    ++j;
                }
                ++k;
            }

            while (i < n1) {
                arr[k] = L[i];
                ++i;
                ++k;
            }

            while (j < n2) {
                arr[k] = R[j];
                ++j;
                ++k;
            }
        }

        static void mergesort(std::vector<T>& arr, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;

                mergesort(arr, left, mid);
                mergesort(arr, mid + 1, right);

                merge(arr, left, mid, right);
            }
        }
    };

	// ***************** <<_USAGE_>> *****************
	void mergeSortUsage() {
		std::vector<int> arr;
		arr.push_back(10);	
		arr.push_back(7);	
		arr.push_back(8);	
		arr.push_back(9);	
		arr.push_back(1);	
		arr.push_back(5);	

		std::cout << "Original array:\n";
		utils::_showVetor(arr);

		MergeSort<int>::sort(arr);

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

		MergeSort<double>::sort(dbl);

		std::cout << "Sorted array:\n";
		utils::_showVetor(dbl);
	}
}
