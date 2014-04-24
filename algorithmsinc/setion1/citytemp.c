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

int DuplicateNode ( Link inlist, Link duplicate )
{
	FreeNode( duplicate );
	return ( 0 );
}

int DeleteNode ( Link to_delete )
{
	Link curr,
		 prev;
	int i;

	if( Head == NULL )
		return 0;

	for ( prev = NULL, curr = Head;
			curr != NULL && ( i = NodeCmp( to_delete, curr)) > 0;
		  prev = curr, curr = curr->next )
	{
		if ( curr != NULL && i == 0)
		{
			if ( prev )
				prev->Next = curr->Next;
			else
				Head = curr->Next;

			FreeNode( curr );
			NodeCount -= 1;
			return 0;
		}
	}

	return 0;
}

int NodeCmp ( Link a, Link b )
{

	if(a->Temp != b->Temp )
		return (a->Temp - b->Temp);
	return strcmp( a->City, b->City);
}

void CreateList ( void )
{
	Head = NULL;
	NodeCount = 0;
}

void FreeNode ( Link n )
{
	free( n->City);
	free( n );
}

void ShowNodes( void )
{
	Link pn;
	int count,median;

	for ( count = 0, pn = Head; pn; pn = pn->Nex )
	{
		count += 1;
	}

	median = count / 2 + 1;

	if( count )
	{
		count = 0;
		for ( pn = Head; pn; pn = pn->Next )
		{
			printf( "%-20s: %3d", pn->City, pn->Temp );
			count += 1;
			if( count == median )
				printf( " --Median--" );
		}
	}
	else
		printf( "Empty list\n" );

}


int main(int argc, char *argv[] )
{
	FILE *fin;
	char buffer[128];

	struct Node n;

	if( argc != 2 )
	{
		fprintf( stderr, "Usage: citytemp filename.ext\n" );
		exit(1);
	}

	fin = fopen(argv[1], "rt");
	if(fin == NULL)
	{
		fprintf(stderr, "Cannot open/find %s\n", argv[2] );
		exit(1);
	}

	CreateList();

	while ( ! feof ( fine ) )
	{
		if( fgets( buffer, 127, fin) == NULL)
			break;
		buffer [ strlen( buffer ) - 1 ] = '\0';
		n.Citye = strdup ( buffer + 3 );

		buffer[3] = '\0';
		n.Temp = atoi ( buffer );

		if( AddNodeAscend ( &n ) == 0)
		{
			fprintf(stderr, "Error adding node. Aborting\n");
			exit(1);
		}
	}

	ShowNodes();
	printf("\n");
	DeleteNode( Head );
	ShowNodes();

	while (Head && Head->Next )
	{
		printf( "\n" );
		DeleteNode ( Head->Next );
		ShowNodes();
	}

	printf( "\n" );
	DeleteNode( Head );
	ShowNodes();

	fclose( fin );
	return ( 0 )
}
