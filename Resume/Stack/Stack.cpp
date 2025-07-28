// Linked list with nesting structure
#include "stack.h"
#include "..\..\Utilidades\Utilidades\_require.h"

using namespace std;

void res::Stack::Link::initialize(void* dat, Link* nxt) {
	data = dat;
	next = nxt;
}

void res::Stack::initialize() { head = 0; } // An empty list yet...

void res::Stack::push(void* dat) {
	Link* node = new Link;
	node->initialize(dat, head);
	head = node;
}

void* res::Stack::peek() { 
	utils::require(head != 0, "Stack empty");
	return head->data; 
}

void* res::Stack::pop() {
	if(head == 0) return 0;
	void*  result  = head->data;
	Link*  oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}

void res::Stack::cleanup() {
	utils::require(head == 0, "Stack not empty");
}