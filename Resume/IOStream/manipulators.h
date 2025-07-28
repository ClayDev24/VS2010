#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

static void _manipulators() {
	using namespace std;
	char   c1, c2, c3;
	double d1, d2, d3, pi;
	int i = 10;

	cout << "boolalpha:\n";
	cout << boolalpha   << true << endl;
	cout << noboolalpha << true << endl;
	endl(cout);
	
	cout << "showpoint:\n";
	d1=30.0;
	d2=10000.0;
	pi=3.1416;
	cout.precision(5);
	cout <<   showpoint << d1 << '\t' << d2 << '\t' << pi << endl;
	cout << noshowpoint << d1 << '\t' << d2 << '\t' << pi << endl; // Always written for float-point numbers.
	endl(cout);

	cout << "showpos:\n"; // A positive sigh(+) will be inserted bfore any positive decimal number.
	cout <<   showpos << 1 << '\t' << 0 << '\t' << -1 << endl;
	cout << noshowpos << 1 << '\t' << 0 << '\t' << -1 << endl;
	endl(cout);

	cout << "showbase:\n";
	cout << hex;
	cout << showbase   << 0x4d << endl;
	cout << noshowbase << 0x4d << endl;
	endl(cout);

	cout << "uppercase:\n";
	cout << uppercase   << 77 << endl;
	cout << nouppercase << 77 << endl;
	endl(cout);

	cout << "dec/hex/oct manipulators:\n";
	cout << hex << 10 << endl;
	cout << oct << 10 << endl;
	cout << dec << 10 << endl;
	endl(cout);

	cout << "internal/left/right:\n";
	cout.width(6); cout << internal << -77 << "***" << endl;
	cout.width(6); cout << left     << -77 << "***" << endl;
	cout.width(6); cout << right    << -77 << "***" << endl;
	endl(cout);
			
	d1 = 3.1415926534;
	d2 = 2006.0;
	d3 = 1.0e-5;
	cout.precision(5);
	cout               << d1   << '\t' << d2   << '\t' << d3 << endl;
	cout << fixed      << d1   << '\t' << d2   << '\t' << d3 << endl;
	cout << scientific << d1   << '\t' << d2   << '\t' << d3 << endl;
		
	istringstream iss("  123");
	iss >> noskipws >> c1 >> c2 >> c3;
	cout << c1 << c2 << c3 << endl;	
	iss.seekg(0);
	iss >> skipws >> c1 >> c2 >> c3;
	cout << c1 << c2 << c3 << endl;
	
	ofstream outfile("test.txt");
	outfile << nounitbuf <<  "Test " << "file" << endl;
	outfile.close();
		
	cout << hex << setiosflags (ios_base::showbase);
	cout << 100 << endl;
	cout << resetiosflags (ios_base::showbase) << 100 << endl;
	
	cout << setbase (16);
	cout << 100 << endl;
	
	cout << setfill ('x') << setw (10);
	cout << dec << 77 << endl;

	cout << hex << setiosflags(ios_base::showbase | ios_base::uppercase);
	cout << 100 << endl;
	cout << hex << resetiosflags(ios_base::showbase | ios_base::uppercase);
	cout << 100 << endl;

	d1 = 3.14159;
	cout << setprecision(5) << d1 << endl;
	cout << setprecision(9) << d1 << endl;
	cout << fixed;
	cout << setprecision(5) << d1 << endl;
	cout << setprecision(9) << d1 << endl;

	outfile.open("test.txt");
	outfile << unitbuf <<  "Test " << "file" << endl;
	outfile.close();
	char a[10], b[10];
	istringstream iss2("one \n \t two");
	iss2 >> noskipws;
	iss2 >> a >> ws >> b;
	cout << a << "," << b << endl;	
}