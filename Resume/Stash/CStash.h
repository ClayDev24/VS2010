#ifndef _CSTASH_
#define _CSTASH_
// Illustrates a C-like lib

// A runtime array-like (DATA) obj:
typedef struct CStashTag {	// in case of selfreferencin' (linked list)
	// defaults to public in C:
	int size;				// Size of each space
	int total;				// Number of storage spaces
	int next;				// Next empty space
	unsigned char *storage;	// Ptr o'dynamic array o'bytes.
} CStash;					// a new type
// Global functions to act exclusively on data above
// Name decorated to avoid names clash:
void  CStash_initialize(CStash *s, int size);// Allocatin'resources n'initialization chores.
void  CStash_clean(CStash *s);			// Releasin'storages.
int   CStash_size (CStash *s);
int   CStash_add  (CStash *s, const void* data);
void  CStash_grow (CStash *s, int increase);
void *CStash_get  (CStash *s, int index);

// ***************** <<_USAGE_>> *****************
void CStashUsage();

#endif // _CSTASH_
