#pragma once
#include <iostream>
#include <iterator>
#include <list>

static void _distance() {
	using namespace std;
	list<int> mylist;
	for(int i=0; i<10; i++)
		mylist.push_back(i*10);
	
	list<int>::iterator first = mylist.begin();
	list<int>::iterator last  = mylist.end();
	
	cout << "The distance is: " << distance(first, last) << endl;
}