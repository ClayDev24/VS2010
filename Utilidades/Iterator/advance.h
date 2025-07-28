#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

static void _advance() {
	using namespace std;
	list<int>   l;
	vector<int> v;
	for(int i=0; i<10; i++) {
		l.push_back(i*10);
		v.push_back(i*10);
	}
	
	list<int>::iterator   it  = l.begin();
	vector<int>::iterator it2 = v.begin();
	
	advance(it, 5);
	advance(it2, 5);
	
	cout << "The sixth element in list   is: " << *it << endl;
	cout << "The sixth element in vector is: " << *it2 << endl;
}