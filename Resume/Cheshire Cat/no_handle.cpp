#include "no_handle.h"

void NoHandle::init() {
	noSmile.i = 0;
	noSmile.f = 12.34f;
}

int NoHandle::get() {
	return noSmile.i;
}

void NoHandle::set(int x) {
	noSmile.i = x;
}