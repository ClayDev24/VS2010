//: C06:BinderValue.cpp
// The bound argument can vary
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int boundedRand() { return rand() % 100; }

int main() {
  const int sz = 20;
  int a[sz], b[sz] = {0};
  generate(a, a + sz, boundedRand);
  int val = boundedRand();
  int* end = remove_copy_if(a, a + sz, b,
                            bind2nd(greater<int>(), val));
  // Sort for easier viewing:
  sort(a, a + sz);
  sort(b, end);
  ostream_iterator<int> out(cout, " ");
  cout << "Original Sequence:\n";
  copy(a, a + sz, out); cout << endl;
  cout << "Values less <= " << val << endl;
  copy(b, end, out); cout << endl;
} ///:~
