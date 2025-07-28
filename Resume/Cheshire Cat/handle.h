#pragma once

class Handle {	// Handle class (Cheshire Cat) technique.
// class/struct declaration only. Definition is hidden away in a implementation file(obj|lib|dll)
	struct Cheshire;
	// It is enought info 2 create a ptr. To create an obj itself a body must be defined:
	Cheshire *smile;
public: // As long as the interface aint change the files that include this one won't b recompiled.
		// The implementation file can change at will.
		// So it'll be the only thing 2b recompiled and relinked w/ the project.
		void init();
		void cleanup();
		int  get();
		void set(int);
};