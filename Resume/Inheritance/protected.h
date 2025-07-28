//: C14:Protected.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// The protected keyword
#pragma once

class Base {
	int i;
protected:
	inline int read() const { return i; }
	inline void set(int ii) { i = ii; }
public:
	Base(int ii = 0) : i(ii) {}
	inline int value(int m) const { return m*i; }
};

class Derived : public Base {
	int j;
public:
	Derived(int jj = 0) : j(jj) {}
	inline void change(int x) { set(x); }
}; 
