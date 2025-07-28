//: C11:Display.h
// Prevents ostream collisions
#ifndef DISPLAY_H
#define DISPLAY_H
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include <iostream>
#include <sstream>

class Display { // Share one of these among all threads
  ZThread::Mutex iolock;
public:
  void output(std::ostringstream& os) {
    ZThread::Guard<ZThread::Mutex> g(iolock);
    std::cout << os.str();
  }
};
#endif // DISPLAY_H ///:~
