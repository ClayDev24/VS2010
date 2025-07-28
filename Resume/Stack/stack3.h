#pragma once
// 1- Struct w/ function members;
// 2- Stack  w/ class (access specifiers);
// 3- Constructor/Destructor:

namespace res {

	class Stack3 {
		struct Link { // Nested struct
			void* data;
			Link* next;
			Link(void* dat, Link* nxt);
			~Link();
		}* head; // = Link* head; // C syntax
	public:
		Stack3();
		~Stack3();
		void  push(void* dat);
		void* peek(); // Returns data ptr from the top o'the Stack and removes the top element.
		void* pop();  // Returns data ptr form teh top o'the Stack but leaves  the top element.
	};

} // res