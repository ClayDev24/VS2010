//: C05:Unroll.cpp
// Unrolls an implicit loop via inlining
#include <iostream>
using namespace std;

template<int n>
inline int power(int m) {
   return power<n-1>(m) * m;
}
template<>
inline int power<1>(int m) {
   return m;
}
template<>
inline int power<0>(int m) {
   return 1;
}
int main()
{
   int m = 4;
   cout << power<3>(m) << endl;
} ///:~
