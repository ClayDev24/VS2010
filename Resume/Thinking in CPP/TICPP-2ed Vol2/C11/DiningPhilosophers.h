//: C11:DiningPhilosophers.h
// Classes for Dining Philosohophers
#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H
#include "zthread/Condition.h"
#include "zthread/Guard.h"
#include "zthread/Mutex.h"
#include "zthread/Thread.h"
#include "Display.h"
#include <iostream>
#include <cstdlib>

class Chopstick {
  ZThread::Mutex lock;
  ZThread::Condition notTaken;
  bool taken;
public:
  Chopstick() : notTaken(lock), taken(false) {}
  void take() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    while(taken)
      notTaken.wait();
    taken = true;
  }
  void drop() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    taken = false;
    notTaken.signal();
  }
};

class Philosopher : public ZThread::Runnable {
  Chopstick& left;
  Chopstick& right;
  int id;
  int ponderFactor;
  ZThread::CountedPtr<Display> display;
  int randSleepTime() {
    if(ponderFactor == 0) return 0;
    return rand()/(RAND_MAX/ponderFactor) * 250;
  }
public:
  Philosopher(Chopstick& l, Chopstick& r,
  ZThread::CountedPtr<Display>& disp, int ident,int ponder)
  : left(l), right(r), display(disp),
    id(ident), ponderFactor(ponder) { srand(time(0)); }
  virtual void run() {
    try {
      while(!ZThread::Thread::interrupted()) {
        {
          std::ostringstream os;
          os << *this << " thinking" << std::endl;
          display->output(os);
        }
        ZThread::Thread::sleep(randSleepTime());
        // Hungry
        {
          std::ostringstream os;
          os << *this << " grabbing right" << std::endl;
          display->output(os);
        }
        right.take();
        {
          std::ostringstream os;
          os << *this << " grabbing left" << std::endl;
          display->output(os);
        }
        left.take();
        // Eating
        {
          std::ostringstream os;
          os << *this << " eating" << std::endl;
          display->output(os);
        }
        ZThread::Thread::sleep(randSleepTime());
        right.drop();
        left.drop();
      }
    } catch(ZThread::Synchronization_Exception& e) {
      std::ostringstream os;
      os << *this << " " << e.what() << std::endl;
      display->output(os);
    }
  }
  friend std::ostream&
  operator<<(std::ostream& os, const Philosopher& p) {
    return os << "Philosopher " << p.id;
  }
};
#endif // DININGPHILOSOPHERS_H ///:~
