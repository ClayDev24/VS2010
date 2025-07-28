#pragma once
// 1- Struct w/ function members;
// 2- Stack w/ class (access specifiers):

namespace res {

	class Stack2 {
		struct Link { // Nested struct
			void* data;
			Link* next;
			void initialize(void* dat, Link* nxt);
		}* head; // = Link* head; // C syntax
	public:
		void  initialize();
		void  cleanup();
		void  push(void* dat);
		void* peek(); // Returns data ptr from the top o'the Stack and removes the top element.
		void* pop();  // Returns data ptr form teh top o'the Stack but leaves  the top element.	
	};

} // res