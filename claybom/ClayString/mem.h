#pragma once
#include "defines.h"
typedef unsigned char byte;

namespace clb {

	class Mem {
		byte *m_memo;
		int   m_size;
	public:
		//Mem();
		Mem(int size = 0);
		~Mem()     { delete []m_memo;
					 DS_(~Mem()...) }
		int size() { return m_size;   }
		byte *pointer(int minSize = 0);
		byte *memo() { return m_memo; }
	};
	// ***************** <<_USAGE_>> *****************
	static void MemUsage() {
		const int SZ = 100;
		Mem *memos[SZ];
		for(int i=0; i<SZ; i++) {
			memos[i] = new Mem(i);
			P_(memos[i]->size())
		}
		for(int i=0; i<SZ; i++) 
			delete memos[i];
	}
};
