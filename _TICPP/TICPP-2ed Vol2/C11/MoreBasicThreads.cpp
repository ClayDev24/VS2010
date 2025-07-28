//: C11:MoreBasicThreads.cpp
// Adding more threads.
//{L} ZThread
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() {
  const int sz = 5;
  try {
    for(int i = 0; i < sz; i++)
      Thread t(new LiftOff(10, i));
    cout << "Waiting for LiftOff" << endl;
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
