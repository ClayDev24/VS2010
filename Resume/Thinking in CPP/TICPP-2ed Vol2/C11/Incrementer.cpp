//: C11:Incrementer.cpp
// Destroying objects while threads are still
// running will cause serious problems.
//{L} ZThread
#include "zthread/Thread.h"
#include "zthread/ThreadedExecutor.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class Count {
  static const int sz = 100;
  int n[sz];
public:
  void increment() {
    for(int i = 0; i < sz; i++)
      n[i]++;
  }
};

class Incrementer : public Runnable {
  Count* count;
public:
  Incrementer(Count* c) : count(c) {}
  void run() {
    for(int n = 100; n > 0; n--) {
      Thread::sleep(250);
      count->increment();
    }
  }
};

int main() {
  cout << "This will cause a segmentation fault!" << endl;
  Count count;
  try {
    Thread t0(new Incrementer(&count));
    Thread t1(new Incrementer(&count));
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
