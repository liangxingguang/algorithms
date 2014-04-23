#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*--data definitions--*/

struct Node{
	char *City;
	int Temp;
	struct Node *Next;
};

typedef struct Node * Link;

Link Head;
int NodeCount;

/*--function declarations for linked lists--*/

int AddNodeAscend( Link );  // add a noe
void CreateList( void );    // initialize list
int DeleteNode( Link );     // delete a node
int DuplicateNode( Link, Link );  //handle duplicate insert
void FreeNode( void );    // free a node's memory
void ShowNodes( void );   //show list of nodes
int NodeCmp( Link, Link ); // compare two nodes


/*--function definitions--*/

int AddNodeAscend( Link to_add )
{
	Link	pn,
			prev,
			curr;
	struct	Node dummy;
	int		i;

	/* Make a copy of the input node*/
	pn = ( Link ) malloc ( siezeof ( struct Node ));
	if(pn == NULL)
		return ( 1 );
	memcpy( pn, to_add, siezeof( struct Node ));

	dummy.Next = Head;
	prev = &dummy;
	curr = Head;

	for(;; prev = curr, curr = curr->Next)
	{
		if(curr == NULL)
			break;
		i = NodeCmp( pn, curr );
		if(i <= 0)
		break;
	}

	if( curr && i == 0 )
	{
		if( DuplicateNode ( curr, pn) == 0 )
			return ( 1 );
	}

	prev->Next = pn;
	pn->Next = curr;
	Head = dummy.Next;
	return ( 0 );
}


