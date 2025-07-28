//: C11:DeadlockingDiningPhilosophers.cpp
// Dining Philosophers with Deadlock
//{L} ZThread
#include "DiningPhilosophers.h"
#include "zthread/ThreadedExecutor.h"
#include <cstdlib>
using namespace ZThread;
using namespace std;

int main(int argc, char* argv[]) {
  int ponder = argc > 1 ? atoi(argv[1]) : 5;
  cout << "Press <ENTER> to quit" << endl;
  static const int sz = 5;
  try {
    CountedPtr<Display> d(new Display);
    ThreadedExecutor executor;
    Chopstick c[sz];
    for(int i = 0; i < sz; i++) {
      int j = (i+1) > (sz-1) ? 0 : (i+1);
      executor.execute(
        new Philosopher(c[i], c[j], d, i, ponder));
    }
    cin.get();
    executor.interrupt();
    executor.wait();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
