// Callbacks in C++
// To make things easy, we put all code in one file.
// Large parts of this should go to thread.hpp/cpp in real real life.
#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdlib.h>
#include <time.h>
#include <process.h>

#include <string>
#include <iostream>

static  int randrange(int _low, int _high)
{
    return rand() / (RAND_MAX / (_high - _low + 1)) + _low;
}
///////////////////////////////////////////////////////////////////////
// A thread base class
///////////////////////////////////////////////////////////////////////
class Thread {
public:
    virtual ~Thread() {}
    void run();
    unsigned long pid() const { return m_pid; }

protected:
    Thread();
    virtual void code() = 0;

private:
    int running;
    unsigned long m_pid;

    static void dispatch(void* thread_obj);
};

Thread::Thread():running(0), m_pid(0L) {}

void Thread::run() {
    // Don't start two threads on the same object
    if (running) return;

    // Create an OS thread, using the static callback
    m_pid = _beginthread(Thread::dispatch, 0, this);
    running = 1;
}

void Thread::dispatch(void* thread_obj)
{
    // Call the actual OO thread code
    ((Thread*)thread_obj)->code();

    // After code() returns, kill the thread object
    delete (Thread*)thread_obj;
}
///////////////////////////////////////////////////////////////////////
// An example thread class
///////////////////////////////////////////////////////////////////////
class Dice : private Thread {
public:
    static void Dice::create(const char* dicename);
    static CRITICAL_SECTION sync;

private:
    Dice(const char* dicename) : name(dicename) {}
    virtual void code();

    std::string name;
};

CRITICAL_SECTION Dice::sync;

void Dice::create(const char* dicename)
{
    (new Dice(dicename))->run();
}


void Dice::code() {
    EnterCriticalSection(&sync);
    std::cout << "Started thread #" << pid() << " for " << name.c_str() << std::endl;
    LeaveCriticalSection(&sync);

    srand(time(0) * pid());

    for(;;) {
        int val = randrange(1, 6);

        EnterCriticalSection(&sync);
        std::cout << name.c_str() << " rolled " << val << std::endl;
        LeaveCriticalSection(&sync);

        Sleep(randrange(100, 500)); // wait up to 500 ms
    }
}
///////////////////////////////////////////////////////////////////////
// Let's test!
///////////////////////////////////////////////////////////////////////
static int _thread2() {
    InitializeCriticalSection(&Dice::sync);

    Dice::create("dice1");
    Dice::create("dice2");

    Sleep(5 * 1000L); // roll dice for 5 seconds
}

