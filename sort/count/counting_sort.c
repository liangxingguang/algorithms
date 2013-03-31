#include<stdio.h>
#include<stdio.h>
#include<string.h>
#define MAXSIZE 10

void counting_sort(int* arr, int* arr1, int length)
{
	int countarr[MAXSIZE]={0};
	int i,j=0;
	for(; i <= length-1; i++)
	{
		//printf("%d",arr[i]);
		//计算相同元素的个数
		countarr[arr[i]] = countarr[arr[i]] + 1;
	}

	for(j = 1 ; j <= MAXSIZE - 1; j++)
	{
		//计算元素的位置
		countarr[j] = countarr[j] + countarr[j-1];
	}

	for(j = length -1; j >=0; j--)
	{
		arr1[countarr[arr[j]]-1] = arr[j];
		countarr[arr[j]] = countarr[arr[j]] - 1;
	}
}


int main(char* argv[], int argc)
{
	int arr1[10] = {0};
	int arr[10] = {2,1,3,5,4,2,6,5,7,3};
	//int arr1[10] = {0};
	int i =0;
	printf("before sort, the array is: ");
	for(; i <= 9; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	counting_sort(arr, arr1, 10);
	printf("after sort, the array is: ");
	for(i = 0; i <= 9; i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");
	return 0;
}

