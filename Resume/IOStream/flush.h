#pragma once
#include <fstream>
#include <iostream>

static void _flush() {
	using namespace std;
	ofstream outfile("test.txt");
	// All unwritten characters in the buffer are written to
	// its controlled output sequence as soon as possible ("flushed").	
	for (int i=0; i<100; i++) { // the content of the file test.txt is updated 100 times.
		outfile << i;
		outfile.flush();
		if(outfile.bad())
			cout << "badbit is set due to flush error operation...\n";
	}
	// Usin' manipulator:
	for(int i=0; i<100; i++) {
		outfile << i << flush; // 100 times updated.
		if(outfile.bad())
			cout << "badbit is set due to flush error operation...\n";
	}
	outfile.close();
}