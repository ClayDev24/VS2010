#pragma once
#include <iostream>
#include <typeinfo.h>	// typeid()

template<class Type1, class Type2, int num>
class CMyClass {
protected:
    Type1 data1;
    Type2 data2;
    int data3;
public:
    CMyClass(Type1 arg1, Type2 arg2, int num) {
		data1 = arg1;
        data2 = arg2;
        data3 = num;
    }
    ~CMyClass() {}
	inline void show() {
		std::cout << "The type of " << data1 << " is " << typeid(data1).name() << std::endl;
		std::cout << "The type of " << data2 << " is " << typeid(data2).name() << std::endl;
		std::cout << "The type of " << data3 << " is " << typeid(data3).name() << std::endl;
	}
};

// ***************** <<_USAGE_>> *****************
static void _template2Usage() {
	CMyClass<double, char, 0> myClass(15.0, 'A', 10);
	myClass.show();
}
