// Illustrates the RAII nature of auto_ptr
#pragma once
#include <memory>
#include <iostream>

class TraceHeap {
	int i;
public:
	static void* operator new(size_t sz) {
		void *p = ::operator new(sz);
		cout << "Allocating TraceHeap obj on the heap at adrs: " << p << endl;
		return p;
	}
	static void operator delete(void* p) {
		cout << "Deleting   TraceHeap obj on the heap at adrs: " << p << endl;
		::operator delete(p);
	}
	TraceHeap(int i): i(i) {}
	inline int get_i() const { return i; }
};

static void _auto_ptr() {
	using namespace std;
	TraceHeap          *man_Ptr=new TraceHeap(4);
	auto_ptr<TraceHeap> aut_Ptr(new TraceHeap(5));
	// Displays:
	cout << "man_Ptr->get_i():" << man_Ptr->get_i() << endl;  // prints 5
	cout << "aut_Ptr->get_i():" << aut_Ptr->get_i() << endl;  // overloaded operator-> to simulate indirection.
	delete man_Ptr; // Need to be manually destroyed.
	// aut_Ptr automatically destroyed here durin' Stack Unwindin' while obj goes outta scope.
}