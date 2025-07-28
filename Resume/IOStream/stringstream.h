#pragma once
#include <iostream>
#include <sstream>
#include <string>

static void _stringstream() {
	using namespace std;
	int val;

// istringstream:
	string stringvalues = "125 320 512 750 333";
	istringstream iss(stringvalues);// default mode = (openmode which = ios_base::out|ios_base::in);
	
	for(int i=0; i<5; i++) {
		iss  >> val;
		cout << val << endl;
	}

// ostringstream:
	ostringstream oss(ostringstream::out);
	oss  << "This is a test";
	ostringstream oss2("Tested!");
	cout << oss.str() << endl << oss2.str() << endl;


// rdbuf for in:
	stringbuf *pbuf;
	//istringstream iss;
	string mystr("This is a sample string\n");
	iss.str(mystr);
	
	pbuf = iss.rdbuf();
	
	int sz = static_cast<int>(pbuf->in_avail());
	
	for (int i=0; i<sz; i++)
		cout << (char)pbuf->sbumpc();	
	
// rdbuf for out:
	//ostringstream oss;
	
	pbuf = oss.rdbuf();
	pbuf->sputn(" add this", 13);
	cout << pbuf->str() << endl;
	pbuf->str("content changed...");
	cout << pbuf->str() << endl;

	oss.str("claybom");
	mystr = oss.str();
	cout << mystr << endl;
}