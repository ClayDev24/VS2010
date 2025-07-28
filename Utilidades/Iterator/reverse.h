#pragma once
#include <iostream>
#include <iterator>
#include <vector>

static void _reverse() {
	using namespace std;

	vector<int> v;
	for (int i=0; i<10; i++)
		v.push_back(i);

	typedef vector<int>::iterator iter_int;
	// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_int begin(v.begin());						//   ^                    
	//         ------>
	iter_int end(v.end());							//                       ^
	//                      
	reverse_iterator<iter_int> rev_end(begin);     // ^                    
	//         <------     
	reverse_iterator<iter_int> rev_iterator(end);  //                     ^

	for( ; rev_iterator < rev_end; ++rev_iterator)
		cout << *rev_iterator << " ";
	cout << endl;
}