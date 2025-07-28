#pragma once
#include <iostream>

static void _in_avail() {
	using namespace std;
	streamsize size;
	char ch;
	
	streambuf *pbuf;
	pbuf = cin.rdbuf();
	
	cout << "Please enter some characters: ";
	cin  >> ch;
	
	size = pbuf->in_avail();
	
	cout << "The first character you entered is: " << ch << endl;
	cout << size << " additional characters in input buffer" << endl;
}