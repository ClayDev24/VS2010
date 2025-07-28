// Standard C Library. See page 86-87 TIPP (vol2)
#include <stdio.h>
#include <stddef.h>
#include <Windows.h>
// Standard C++ Library:
//#include <cstdio>
//#include <cstddef>

struct mystruct {
	char singlechar;
	char arraymember[10];
	char anotherchar;
};

int main() {
	printf("offsetof(mystruct,singlechar) is %d\n",  offsetof(mystruct, singlechar));
	printf("offsetof(mystruct,arraymember) is %d\n", offsetof(mystruct, arraymember));
	printf("offsetof(mystruct,anotherchar) is %d\n", offsetof(mystruct, anotherchar));
	
	system("pause");
	return(0);
}