#pragma once

static void func(int) {}

// Used mainly to highlight casts (for future easily huntin') or to eliminate warnings.
static void _static_cast() {
	int   i = 0x7fff; // Max pos value = 32767
	long  l;
	float f;
// (1) Typical castless (safe) conversions:
	l = i; // Promotion cast
	f = (float)i; // to a larger type. Do not lose info.
	// Unnecessary use (as shown above). Jus'used to highlight the promotion:
	l = static_cast<long>(i);
	f = static_cast<float>(i);

// (2) Narrowing (not that safe) conversions:
	i = l; // May lose digits
	i = f; // Compiler allow with a warning msg
	// Use it to say "I know," to eliminates warnings:
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i);

// (3) void* cast: All forms r = dangerous but C++ style is easily 2 locate when huntin'4 bugs.
	void* vp = &i;
	//float* fp  = vp;	// ERROR!			// only C
	float* fp1 = (float*)vp;				// C/C++
	float* fp2 = static_cast<float*>(vp);	// only C++

// (4) Implicit (automatic) type conversions performed by the compiler:
	double d = 0.0;
	func(d); // Automatic type conversion.       Compiler WARNING
	func(static_cast<int>(d)); // More explicit. Eliminates Warning.
}