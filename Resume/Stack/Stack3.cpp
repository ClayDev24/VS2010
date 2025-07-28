// Linked list with nesting structure
#include "stack3.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

res::Stack3::Link::Link(void* dat, Link* nxt) {
	data = dat;
	next = nxt;
}

res::Stack3::Link::~Link() { /*dat ptr user ownership*/ }

res::Stack3::Stack3() { head = 0; } // An empty list yet...

res::Stack3::~Stack3() {
	utils::require(head == 0, "Stack3 not empty. Memory leaks!");
}

void res::Stack3::push(void* dat) {
	// Neatly allocates a new Link (dynamic obj creation)
	// and initializes head pointer:	
	head = new Link(dat, head);
}

void* res::Stack3::peek() { 
	utils::require(head != 0, "Stack empty");
	return head->data; 
}

void* res::Stack3::pop() {
	if(head == 0) return 0;
	void*  result  = head->data;
	Link*  oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}