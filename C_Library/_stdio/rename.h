#include <stdio.h> // Standard C Lib.

void _rename() {
	// If oldname and newname specify different paths and this is supported by the system,
	// the file is moved to the new location.
	if(!rename("alphabet.txt", "newname.txt"))
		puts("File successfully renamed");
	else
		perror("Error renaming file");
}