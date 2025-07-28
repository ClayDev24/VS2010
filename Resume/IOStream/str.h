#pragma once
#include <iostream>
#include <sstream>
#include <string>

static void _str() {
	using namespace std;
	stringbuf *pbuf;
	istringstream iss;
	string mystr("This is a sample string\n");
	
	iss.str(mystr);
	
	pbuf = iss.rdbuf();
	
	int size = static_cast<int>(pbuf->in_avail());
	
	for(int n=0; n<size; n++)
		cout << (char)pbuf->sbumpc();
}