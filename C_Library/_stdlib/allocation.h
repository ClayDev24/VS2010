#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.

void allocation() {
	int strSz, i, n, cnt = 0;
	char *buf;
	int  *pData, *buffer1, *buffer2, *buffer3 = NULL;	
	unsigned int *ptr = NULL; // likes malloc
// malloc:
	strSz = 26;
	buf = (char*)malloc(strSz+1);
	if(!buf)
		exit(1);
	for(i=0; i<strSz; i++)
		buf[i] = rand()%26+'a';
	buf[i]='\0'; // Null terminated char str.

	printf("Random string: %s\n", buf);
	free(buf);
// calloc:
	n = 5;
	pData = (int*)calloc(n, sizeof(int));
	if(!pData)
		exit(1);
	for(i=0; i<n; i++) {
		pData[i]=i*2;
		printf("pData[%d]: %d\n", i, pData[i]);
	}
	free(pData);
// realloc:
	do {
		printf("Enter an integer value (0 to end): ");
		scanf("%d", &i);
		ptr = (int*)realloc(ptr, ++cnt*sizeof(int));
		if(!ptr) {
			puts("Error (re)allocating memory");
			exit(1);
		}
		ptr[cnt-1] = i;
	} while(i);
	printf("Numbers entered:\n");
	for(i=0; i<cnt; i++)
		printf("ptr[%d]: %d\n", i, ptr[i]);
	free(ptr);
// free:	
	buffer1 = (int*)malloc(100, sizeof(int));
	buffer2 = (int*)calloc(100, sizeof(int));
	buffer3 = (int*)realloc(buffer2, 500*sizeof(int));
	free(buffer1);
	free(buffer3);
	//free(buffer2); // ERROR!
}