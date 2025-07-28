#pragma once
#include <iostream>
#include <iterator>
#include <vector>

static void _back_insert() {
	using namespace std;

	vector<int> v1, v2;
	for(int i=1; i<=5; i++) {
		v1.push_back(i);
		v2.push_back(i*10);
	}
	
	back_insert_iterator<vector<int>> back_it(v1);
	
	copy(v2.begin(), v2.end(), back_it);
	
	vector<int>::iterator it;
	for(it=v1.begin(); it!= v1.end(); ++it)
		cout << *it << " ";
	cout << endl;
}