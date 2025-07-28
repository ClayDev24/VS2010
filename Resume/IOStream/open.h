#pragma once
#include <iostream>
#include <fstream>

static void _open() {
	using namespace std;
	ifstream ifile;
	filebuf *pbuf = ifile.rdbuf();
	pbuf->open("test.txt", ios::out);
	
	if(pbuf->is_open()) {
		cout << "file is open.\n";
		pbuf->close();
	} else
		cout << "file is not open.\n";	
	
	ifile.open("test.txt");
	if(ifile.is_open()) {
		while (ifile.good())
			cout << (char)ifile.get();
		ifile.close();
	} else
		cout << "Error opening file\n";
	
	fstream file;
	file.open("test2.txt", ios::out);
	if(file.is_open()) {
		if(file.good())
			file << "File successfully open";
		file.close();
	} else
		cout << "Error opening file\n";
}