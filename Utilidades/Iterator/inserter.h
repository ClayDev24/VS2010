#pragma once
#include <iostream>
#include <iterator>
#include <list>

static void _inserter() {
	using namespace std;

	list<int> l1, l2;
	for(int i=1; i<=5; i++) {
		l1.push_back(i);
		l2.push_back(i*10);
	}
	
	list<int>::iterator it = l1.begin();
	advance(it, 3);
	
	copy(l2.begin(), l2.end(), inserter(l1, it));
	
	for(it = l1.begin(); it!= l1.end(); ++it)
		cout << *it << " ";
	cout << endl;
}