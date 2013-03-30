#include<stdio.h>
#include<string.h>
void quicksort(int *arr,int start,int end);
int  partition(int *arr, int start, int end);
void exchange(int *arr, int start, int end);


void quicksort(int *arr, int start, int end)
{
	int key = 0;
	if(start < end)
	{
		key = partition(arr, start, end);

		quicksort(arr, start, key - 1);
		quicksort(arr, key + 1, end);
	}
}

int partition(int *arr, int start, int end)
{
	int keyvalue = *(arr + end);
	int i = start-1;
	int j=0;
	for(j = start; j <= ( end - 1); j++)
	{
		if(*(arr + j) >= keyvalue)
		{
			i += 1;
			exchange(arr, i, j);
		}
	}

	exchange(arr, i+1, end);
	return i+1;

}

void exchange(int *arr, int start, int end)
{
	int temp = *(arr + start);
	*(arr + start) = *(arr + end);
	*(arr + end) = temp;
}

int main(char *argr[], int argc)
{
	int i=0;
	int arr[10] = {9,1,7,3,8,4,6,5,2,10};
	printf("before the sort,the array is:");
	for(;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	quicksort(arr, 0,9);
	printf("after the sort,the array is:");
	for(i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
