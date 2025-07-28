// Linked list with nesting
#include "Stack.h"
#include "Stack2.h"
#include "../../include/require.h"
using namespace std;

Stack::Link::Link(void *dt, Link *nxt):data(dt), next(nxt) {}

void Stack::push(void *dt) {
	Link *newLink = new Link(dt, head);
	head = newLink;
}

void* Stack::peek() const { 
	require(head != 0, "Stack empty");
	return head->data; 
}

void* Stack::pop() {
	if(head == 0) return 0;
	void *result  = head->data;
	Link *oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}

Stack::~Stack() {
	require(head == 0, "Stack not empty");
} ///:~
