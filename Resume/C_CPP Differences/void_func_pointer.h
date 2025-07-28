#pragma once

static void _void_func_pointer() {
	int i = 0;
// void* (dangerous) cast:
	// C/C++: Assign any ptr 2 void ptr is the original intent of it
	void * vp  = &i;
	// C++: Assign void ptr 2 any ptr requires a cast
//	int*   fp  = vp;						// C		Not so stricter type checkin'
	float* fp1 = (float*)vp;				// C/C++	Cast is required to tell the reader/compiler you know what you're doin'.
	//float* fp2 = static_cast<float*>(vp);	// C++		Stricter Type checkin' language
}