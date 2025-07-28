#ifndef __CLIB_H__
#define __CLIB_H__

// A runtime array-like (DATA) obj:
typedef struct CStashTag { // in case of selfreferencin' (linked list)
	int m_typeSz;	// Size o'each space
	int m_total;	// Number o'storage spaces
	int m_next;		// Next empty space
	unsigned char* m_storage; // Ptr o'dynamic array o'bytes.
} CStash; // a new type
// Global functions 2 act exclusively on Stash data.
// Name decorated to avoid name clashes beteween libs:
void  CStash_clean(CStash* s);			// Releasin'storages.
void  CStash_init (CStash* s, int size);// Allocatin'resources n'initialization chores.
void  CStash_grow (CStash* s, int increase);
void* CStash_get  (CStash* s, int index);
int   CStash_add  (CStash* s, const void* data);

#endif // __CLIB_H__
