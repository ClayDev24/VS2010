#pragma once
#include <iostream>

static void _sputbackc() {
	using namespace std;
	char ch;
	long n;
	streambuf *pbuf;
	
	pbuf = cin.rdbuf();
	cout << "Please enter some letters and then a number: ";
	do {
		ch = pbuf->sbumpc(); // Get current character and increase get pointer
		if((ch>='0') && (ch <='9')) {
			pbuf->sputbackc(ch); // Put character back
			// SUNGETC:
			//pbuf->sungetc();
			cin  >> n;
			cout << "You entered number " << n << endl;
			break;
		}
	} while(ch != EOF);
}