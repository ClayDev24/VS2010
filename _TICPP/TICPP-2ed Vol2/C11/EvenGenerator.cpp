//: C11:EvenGenerator.cpp
// When threads collide.
//{L} ZThread
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class EvenGenerator : public Generator {
  int currentEvenValue;
public:
  EvenGenerator() { currentEvenValue = 0; }
  ~EvenGenerator() { cout << "~EvenGenerator" << endl; }
  int nextValue() {
    currentEvenValue++; // Danger point here!
    currentEvenValue++;
    return currentEvenValue;
  }
};

int main() {
  EvenChecker::test<EvenGenerator>();
} ///:~
