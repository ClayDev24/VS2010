#pragma once
#include <iostream>
using namespace std;

class Widget {
	void a(int i) const { cout << "Widget::a()..." << i << endl; }
	void b(int i) const { cout << "Widget::b()..." << i << endl; }
	void c(int i) const { cout << "Widget::c()..." << i << endl; }
	void d(int i) const { cout << "Widget::d()..." << i << endl; }
	enum { cnt = 4 };
	void (Widget::*fptr[cnt])(int) const;
public:
	Widget() {
		fptr[0] = &Widget::a; // Full spec required
		fptr[1] = &Widget::b;
		fptr[2] = &Widget::c;
		fptr[3] = &Widget::d;
	}
	void select(int i, int j) {
		if(i < 0 || i >= cnt) return;
		(this->*fptr[i])(j);
	}
	int count() { return cnt; }
};

static void PointerToMemberFunction() {
	Widget w;
	for(int i = 0; i < w.count(); i++)
		w.select(i, i);
}