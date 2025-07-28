// Nested struct in linked list
#pragma once
namespace res {
	// 1- Struct w/ function members:
	struct Stack {
		struct Link { // Nested struct
			void* data;
			Link* next;
			void initialize(void* dat, Link* nxt);
		}* head; // = Link* head; // C syntax
		void  initialize();
		void  cleanup();
		void  push(void* dat);
		void* peek(); // Returns data ptr from the top o'the Stack and removes the top element.
		void* pop();  // Returns data ptr form teh top o'the Stack but leaves  the top element.
	};

} // res