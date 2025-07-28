//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>

// Second Thread function
void ThreadProc(void *param);

// First thread 
int main() {
	int n=0;
	HANDLE handle;
	
	printf("\t Thread Demo\n");
	printf("Enter the number of threads : ");
	
	std::cin >> n;

	for(int i=0; i<n; i++) {
		int val = i + 1;
		handle  = (HANDLE) _beginthread(ThreadProc, 0, &val); // create thread
		WaitForSingleObject(handle, 100);				
	}

	system("pause");
	return(0);
}

void ThreadProc(void *param) {	
	int t = *((int*)param);
	printf("%d Thread is Running!\n", t);

	for(int i=0; i<1000; i++)
		printf("thread:%d %d\n", t, i);

	_endthread();
}

