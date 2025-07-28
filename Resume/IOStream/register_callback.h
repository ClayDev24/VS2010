// stream callbacks
#pragma once
#include <iostream>
#include <fstream>

static void testfn(std::ios_base::event ev, std::ios_base& iosobj, int index) {
	using namespace std;
	switch(ev) {
    case ios_base::copyfmt_event:
		cout << "copyfmt_event\n"; break;
    case ios_base::imbue_event:
		cout << "imbue_event\n"; break;
    case ios_base::erase_event:
		cout << "erase_event\n"; break;
	}
}

static void _register_callback() {
	using namespace std;
	ofstream filestr;
	filestr.register_callback(testfn, 0);
	filestr.imbue(cout.getloc());
}