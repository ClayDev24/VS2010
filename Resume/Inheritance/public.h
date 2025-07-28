#pragma once

class Parent { // So-called base/super/parent class
	int m_i;
public:
	Parent(int _i=0):m_i(_i) {}
	void set(int _i)   { m_i = _i; }
	int  read() const { return m_i; }
	int  permute()    { return m_i *= 47; }
};

class Child : public Parent { // So-called derived/inherited/sub/child class)
	int m_i; // Different from Parent's i
public:
	Child(int _i=0):m_i(_i), Parent(_i) {}
	int change() {
		m_i = permute(); // Different name call
		return m_i;
	}
	void set(int _i) {
		m_i = _i;
		Parent::set(_i); // Same-name function call
	}
};