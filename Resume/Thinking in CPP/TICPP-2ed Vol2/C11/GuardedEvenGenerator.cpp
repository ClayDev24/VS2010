//: C11:GuardedEvenGenerator.cpp
// Simplifying mutexes with the Guard template.
//{L} ZThread
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class GuardedEvenGenerator : public Generator {
  int currentEvenValue;
  Mutex lock;
public:
  GuardedEvenGenerator() { currentEvenValue = 0; }
  ~GuardedEvenGenerator() {
    cout << "~GuardedEvenGenerator" << endl;
  }
  int nextValue() {
    Guard<Mutex> g(lock);
    currentEvenValue++;
    Thread::yield();
    currentEvenValue++;
    return currentEvenValue;
  }
};

int main() {
  EvenChecker::test<GuardedEvenGenerator>();
} ///:~
