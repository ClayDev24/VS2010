//: C11:SimplePriorities.cpp
// Shows the use of thread priorities.
//{L} ZThread
#include "zthread/Thread.h"
#include <iostream>
#include <cmath>
using namespace ZThread;
using namespace std;

class SimplePriorities : public Runnable {
  int countDown;
  volatile double d; // No optimization
  int id;
public:
  SimplePriorities(int ident = 0): countDown(5),id(ident){}
  ~SimplePriorities() throw() {
    cout << id << " completed" << endl;
  }
  friend ostream&
  operator<<(ostream& os, const SimplePriorities& sp) {
    return os << "#" << sp.id << " priority: " 
      << Thread().getPriority() 
      << " count: "<< sp.countDown;
  }
  void run() {
    while(true) {
      // An expensive, interruptable operation:
      for(int i = 1; i < 100000; i++)
        d = d + (M_PI + M_E) / (double)i;
      cout << *this << endl;
      if(--countDown == 0) return;
    }
  }
};

int main() {
  try {
    Thread high(new SimplePriorities);
    high.setPriority(High);
    for(int i = 0; i < 5; i++) { 
      Thread low(new SimplePriorities(i));
      low.setPriority(Low);
    }
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
