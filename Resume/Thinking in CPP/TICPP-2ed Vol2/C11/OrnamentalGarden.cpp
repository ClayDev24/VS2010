//: C11:OrnamentalGarden.cpp
//{L} ZThread
#include "Display.h"
#include "zthread/Thread.h"
#include "zthread/FastMutex.h"
#include "zthread/Guard.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/CountedPtr.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace ZThread;
using namespace std;

class Count : public Cancelable {
  FastMutex lock;
  int count;
  bool paused, canceled;
public:
  Count() : count (0), paused(false), canceled(false) {
    srand(time(0)); // Seed the random number generator
  }
  int increment() {
    // Comment the following line to see counting fail:
    Guard<FastMutex> g(lock);
    int temp = count ;
    if(rand() < RAND_MAX/2) // Yield half the time
      Thread::yield();
    return (count  = ++temp);
  }
  int value() { 
    Guard<FastMutex> g(lock);
    return count; 
  }
  void cancel() {
    Guard<FastMutex> g(lock);
    canceled = true;
  }
  bool isCanceled() {
    Guard<FastMutex> g(lock);
    return canceled;
  }
  bool pause() {
    Guard<FastMutex> g(lock);
    paused = true;
  }
  bool isPaused() {
    Guard<FastMutex> g(lock);
    return paused;
  }
};

class Entrance : public Runnable {
  CountedPtr<Count> count;
  CountedPtr<Display> display;
  int number;
  int id;
  bool waitingForCancel;
public:
  Entrance(CountedPtr<Count>& cnt, 
    CountedPtr<Display>& disp, int idn) 
  : count(cnt), display(disp), id(idn), number(0),
    waitingForCancel(false) {}
  void run() {
    while(!count->isPaused()) {
      number++;
      {
        ostringstream os;
        os << *this << " Total: "
           << count->increment() << endl;
        display->output(os);
      }
      Thread::sleep(100);
    }
    waitingForCancel = true;
    while(!count->isCanceled()) // Hold here...
      Thread::sleep(100);
    ostringstream os;
    os << "Terminating " << *this << endl;
    display->output(os);
  }
  int getValue() {
    while(count->isPaused() && !waitingForCancel)
      Thread::sleep(100);
    return number; 
  }
  friend ostream&
  operator<<(ostream& os, const Entrance& e) {
    return os << "Entrance " << e.id << ": " << e.number;
  }
};

int main() {
  cout << "Press <ENTER> to quit" << endl;
  CountedPtr<Count> count(new Count);
  vector<Entrance*> v;
  CountedPtr<Display> display(new Display);
  const int sz = 5;
  try {
    ThreadedExecutor executor;
    for(int i = 0; i < sz; i++) {
      Entrance* task = new Entrance(count, display, i);
      executor.execute(task);
      // Save the pointer to the task:
      v.push_back(task);
    }
    cin.get(); // Wait for user to press <Enter>
    count->pause(); // Causes tasks to stop counting
    int sum = 0;
    vector<Entrance*>::iterator it = v.begin();
    while(it != v.end()) {
      sum += (*it)->getValue();
      it++;
    }
    ostringstream os;
    os << "Total: " << count->value() << endl
       << "Sum of Entrances: " << sum << endl;
    display->output(os);
    count->cancel(); // Causes threads to quit
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
