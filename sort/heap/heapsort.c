#include<stdio.h>
#include<string.h>

void sort(int *arr, int size);
void buildheap(int *arr, int size);
void heapify(int *arr, int idx, int size);
void exchange(int *arr, int first, int seconde);


void sort(int *arr, int size)
{
	int i = 0;
	buildheap(arr, size);
	for(i = size -1 ; i >= 0; i--)
	{
		exchange(arr, 0, i);
		heapify(arr, 0, i);
	}
}

void buildheap(int *arr, int size)
{
	int i = size/2 -1;
	for(; i >= 0; i--)
	{
		heapify(arr, i, size);
	}
	for(i=0; i < size; i++)
	{
		printf("%d",arr[i]);
		
	}
	printf("\n");
}

void heapify(int *arr, int idx, int size)
{
	int largest = 0;
	int left = 2*idx + 1;
	
	int right = 2*idx + 2;
	if((left < size) && (*(arr + left) > *(arr + idx)))
	{
		largest = left;
	}
	else
	{
		largest = idx;
	}

	if((right < size) && (*(arr + right) > *(arr + largest)))
	{
		largest = right;
	}

	if(largest != idx)
	{
		exchange(arr, idx, largest);
		heapify(arr, largest, size);
	}
}

void exchange(int *arr, int first, int seconde)
{
	int temp = *(arr + first);
	*(arr + first) = *(arr + seconde);
	*(arr + seconde) = temp;
}

int main(char* argv[], int argc)
{
	int i = 0;
	int arr[10]={8,4,9,5,3,6,1,7,2,0};
	printf("before sort ,the array is:");
	for(i=0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("after sort, the array is:");
	sort(arr,sizeof(arr) / sizeof(int));
	for(i=0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

