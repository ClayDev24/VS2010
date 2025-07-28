#pragma once
#include <iostream>

template<class Type>
class CCompare {
protected:
    Type arg1;
    Type arg2;
public:
    CCompare(Type arg1, Type arg2) {
        CCompare::arg1 = arg1;
        CCompare::arg2 = arg2;
    }
    ~CCompare() {}
    inline Type GetMin() {
        Type min;
        if (arg1 < arg2)
            min = arg1;
        else
            min = arg2;
        return min;
    }
    inline Type GetMax() {
        Type max;
        if (arg1 > arg2)
            max = arg1;
        else
            max = arg2;
        return max;
    }
    inline int Equal() {
        int equal;
        if (arg1 == arg2)
            equal = 1;
        else
            equal = 0;
        return equal;
    }
};
// ***************** <<_USAGE_>> *****************
static void _template1Usage() {
	using namespace std;
	// Teplate1 example:
    CCompare<int> compare1(15, 25);
    CCompare<double> compare2(12.984, 12.985);//(254.78, 12.983);
    CCompare<char> compare3('A', 'Z');
    cout << "THE COMPARE1 OBJECT" << endl;
    cout << "Lowest:  " << compare1.GetMin() << endl;
    cout << "Highest: " << compare1.GetMax() << endl;
    cout << "Equal:   " << compare1.Equal()  << endl;
    cout << endl;
    cout << "THE COMPARE2 OBJECT" << endl;
    cout << "Lowest:  " << compare2.GetMin() << endl;
    cout << "Highest: " << compare2.GetMax() << endl;
    cout << "Equal:   " << compare2.Equal()  << endl;
    cout << endl;
    cout << "THE COMPARE2 OBJECT" << endl;
    cout << "Lowest:  " << compare3.GetMin() << endl;
    cout << "Highest: " << compare3.GetMax() << endl;
    cout << "Equal:   " << compare3.Equal()  << endl;
    cout << endl;
}