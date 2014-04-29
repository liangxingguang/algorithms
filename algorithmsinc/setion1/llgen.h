#ifndef LLGEN_H
#define LLGEN_H 1

struct Node{
	struct Node	*prev;
	struct Node *next;
	void		*pdata;
};

typedef struct Node *Link;

struct Lisk{
	Link			LHead;
	Link			LTail;
	unsigned int	LCount;
	void* ( *LCreateData ) ( void* );
	int   ( *LDeleteData ) ( void* );
	int   ( *LDuplicateNode) (Link, Link);
	int   ( *LNodeDataCmp ) ( void*, void*);
};

int AddNodeAscend ( struct List *, void *);
int AddNodeAtHead ( struct List *, void *);

struct List* CreateLList(
		void* ( * ) ( void* ),
		int   ( * ) ( void* ),
		int   ( * ) ( Link, Link),
		int   ( * ) ( void *, void *));

Link CreateNode (struct List *, void *);
int  DeleteNode (struct List *, Link);
Link FindNode   ( struct List*, void*);
Link FindNodeAscend (struct List*, void*);
Link GotoNext (struct List*, Link);
Link GotoPrev (struct List*, Link);
#endif
