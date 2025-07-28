//: C11:ResponsiveUI.cpp
// Threading for a responsive user interface.
//{L} ZThread
#include "zthread/Thread.h"
#include <iostream>
#include <fstream>
using namespace ZThread;
using namespace std;

class DisplayTask : public Runnable {
  ifstream in;
  static const int sz = 100;
  char buf[sz];
  bool quitFlag;
public:
  DisplayTask(const string& file) : quitFlag(false) {
    in.open(file.c_str());
  }
  ~DisplayTask() { in.close(); }
  void run() {
    while(in.getline(buf, sz) && !quitFlag) {
      cout << buf << endl;
      Thread::sleep(1000);
    }
  }
  void stop() { quitFlag = true; }
};

int main() {
  try {
    cout << "Press <Enter> to quit:" << endl;
    DisplayTask* dt = new DisplayTask("ResponsiveUI.cpp");
    Thread t(dt);
    cin.get();
    dt->stop();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
  cout << "Shutting down..." << endl;
} ///:~
