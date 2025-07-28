#pragma once
#include <iostream>
#include <iterator>
#include <deque>

static void _front_insert() {
	using namespace std;
	deque<int> d1, d2;

	for(int i=1; i<=5; i++) {
		d1.push_back(i);
		d2.push_back(i*10);
	}
	
	front_insert_iterator<deque<int>> front_it(d1);
	
	copy(d2.begin(), d2.end(), front_it);
	
	deque<int>::iterator it;
	for(it=d1.begin(); it!=d1.end(); ++it)
		cout << *it << " ";
	cout << endl;
}