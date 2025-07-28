// typewriter
#pragma once
#include <iostream>
#include <fstream>

static void _put() {
	using namespace std;
	ofstream outfile("test.txt");
	
	char ch;
	cout << "Start typin'...(dot'.' to exit)\n";
	do {
		ch = cin.get();
		outfile.put(ch);
	} while(ch!='.');
}