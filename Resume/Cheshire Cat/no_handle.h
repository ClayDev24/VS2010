#pragma once

class NoHandle {
	// Includin' private structures exposed in a header file cause:
	// 1- Direct access facilities through pointer n' casting;
	// 2- Needless recompilation.
	struct NoCheshire {
		int   i;	// Visible info that might be cracked by hackers
		float f;
	} noSmile;
public:
	void init();
	int  get();
	void set(int);
};