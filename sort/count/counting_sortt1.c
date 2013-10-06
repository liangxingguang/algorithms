#include<stdio.h>
#include<stdlib.h>

int countingsort(int* arr, int n, int k)
{
	int i, idx = 0;
	int *b = calloc(k, sizeof(int));

	for(i = 0; i < n; i++)
	{
		b[arr[i]]++;
	}

	for (i = 0; i <= k; i++)
	{
		while(b[i]-- > 0)
		{
			arr[idx++] = i;
		}
	}
	free(b);
	return 0;
}


//test the function
//

int main(char* argv[], int argc)
{
	int arr[10]={2,1,7,4,6,5,9,8,10,3};
	int i = 0;
	printf("before sort,the array is: ");
	for(; i <= 9; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	countingsort(arr,10,10);
	printf("after sort,the arrary is: ");
	for( i=0; i <= 9; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
