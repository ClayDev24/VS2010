#pragma once
#include <iostream>
#include <memory>
#include <algorithm>

static void _get_temporary_buffer() {
	using namespace std;

	int numbers[]={30,50,10,20,60,40};
	
	// use temporary buffer to sort and show the numbers:
	pair <int*, ptrdiff_t> result = get_temporary_buffer<int>(6);
	if(result.second > 0) {
		uninitialized_copy (numbers, numbers+result.second, result.first);
		sort(result.first, result.first+result.second);
		cout << "sorted numbers  : ";
		for (int i=0; i<result.second; i++)
			cout << result.first[i] << " ";
		cout << endl;
		return_temporary_buffer(result.first);
	}
	// show original numbers:
	cout << "unsorted numbers: ";
	for(int i=0; i<6; i++)
		cout << numbers[i] << " ";
	cout << endl;
}