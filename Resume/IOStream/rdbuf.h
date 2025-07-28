#pragma once
#include <iostream>
#include <fstream>

static void _rdbuf() {
	using namespace std;
	filebuf *pbuf;
	//fstream ifs;
	ifstream ifs;
	pbuf = ifs.rdbuf();
	pbuf->open("test.txt", ios::out);
	
	if(pbuf->is_open()) {
		cout << "file is open.\n";
		// SPUTN:
		pbuf->sputn("First sentence\n", 15);
		pbuf->pubsync(); // Writes any unwritten character in the output buffer to the physical device.
		// SPUTC:
		for(int i=0; i<10; i++)
			pbuf->sputc((char)i+48);
		ifs.close();
	} else
		cout << "file is not open.\n";

	ifstream ifile;
	int sz;
	char *buf;
	ifile.open("rdbuf.h");	
	// get pointer to associated buffer object
	pbuf = ifile.rdbuf();	
	// get file size using buffer's members
	sz = static_cast<int>(pbuf->pubseekoff(0, ios::end, ios::in));
	pbuf->pubseekpos(0, ios::in);	 // Sets abs pos o'the get ptr. First char o'file, in this case.
	// allocate memory to contain file data
	buf = new char[sz];
	// get file data  
	pbuf->sgetn(buf, sz); // Gets up to sz chars from the input sequence n'stores'em in the array pointed by buf.
	ifile.close();
	// write content to stdout
	cout.write(buf, sz);
	delete buf;
	
	filebuf fb;
	fb.open("test2.txt", ios::out);
	ostream os(&fb); // Constructor
	os << "Test sentence\n";
	fb.close();

	char mybuffer[512];
	fstream file;
	file.rdbuf()->pubsetbuf(mybuffer, 512); // If both parameters are zero, the object becomes unbuffered.
	// operations with file stream goes here.

// SGETC Usage:
	ifile.open("rdbuf.cpp");
	pbuf = ifile.rdbuf();
	while(pbuf->sgetc()!=EOF) // Gets char but NOT advance ptr 1 pos.
		cout << (char)pbuf->sbumpc();
	ifile.close();

// SNEXTC Usage:
	ifile.open("test.txt");
	pbuf = ifile.rdbuf();
	do 
		cout << (char)pbuf->sgetc();
	while (pbuf->snextc()!=EOF);
	ifile.close();
}