#include <stdio.h> // Standard C Lib.

void _remove() {
	if(remove("myfile.txt"))
		perror("Error deleting file");
	else
		puts("File successfully deleted");
}