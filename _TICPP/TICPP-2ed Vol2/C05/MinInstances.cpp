//: C05:MinInstances.cpp {O}
#include "OurMin.cpp"
// Explicit Instantiations for int and double
template const int& min<int>(const int&, const int&);
template const double& min<double>(const double&,
                                   const double&);
///:~
