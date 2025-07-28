// Nested struct in linked list
#pragma once

namespace dos {

	class Stack {
	public:
		class Link {
		public:
			Link(void* _data, Link *_nxt) {
				data = _data;
				next = _nxt;
			}
			void* data;
			Link* next;
		} *head;
		Stack():head(0) {};
		~Stack() {
			utils::require(head == 0, "Stack not empty");
		}
		inline void  push(void *dat) {
			Link* node = new Link(dat, head);
			head = node;
		}
		inline void* peek() const {
			utils::require(head != 0, "Stack empty");
			return head->data; 
		}
		inline void* pop() {
			if(head == 0) return 0;
			void*  result  = head->data;
			Link*  oldHead = head;
			head = head->next;
			delete oldHead;
			return result;
		}
	};

} // dos
