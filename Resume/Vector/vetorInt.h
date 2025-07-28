#pragma once
#include <algorithm>// STL, find
#include <iostream>
#include <vector>

typedef std::vector<int>::iterator it; // define iterator type through STL

static void _vetorInt() {
	using namespace std;
	const int max = 100;
	vector<int> v(max); // the container object.
	for(int i=0; i<max; i++)
		v[i] = i;
	while(true) {
		cout << "Enter required number (-1 exit):";
		int n;
		cin >> n;
		if(n==-1)
			break;
		it pos = find(v.begin(), v.end(), n);
		if(pos != v.end())
			cout << "Found at position " << (pos - v.begin()) << endl;
		else
			cout << n << " not found" << endl;
	} // while
} // _vetorInt,
