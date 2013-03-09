
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void quicksort(int* arr, int start, int end);
int partition(int* arr, int start, int end);
void exchange(int* arr, int first, int seconde);
  
//对数组进行递归排序
void quicksort(int* arr, int start, int end)
{
    int index;
    if(start < end)
    {
        index = partition(arr, start, end);
        quicksort(arr, start, index - 1);
        quicksort(arr, index + 1, end);
    }

 }
 
  //对数组进行重排，将数组分成三个部分：大于某个x值的部分，小于某个x值的部分，
  //等于x值的部分，并且返回x值的下标。
 int partition(int* arr, int start, int end)
 {
     //将数组最后的一个值作为比较标准
     int temp = *(arr + end);
     //key作为两个部分的分界点
     int key = start - 1;
      int j;
      for(j = start; j <= end - 1; j++)
      {
          //如果第j个值小于x，则将其放到小于x的部分中
          if(*(arr + j) <= temp)
          {
              key = key + 1;
              exchange(arr, key, j);
          }
      }
    //将x放回两部分之间
  exchange(arr, key + 1, end);
    //返回x的下标
  return key + 1;
  }
  
 void exchange(int* arr, int first, int seconde)
 {
     int temp;
     temp = *(arr + first);
     *(arr + first) = *(arr + seconde);
     *(arr + seconde) = temp;
 }
 
int main(char* arg, int argc)
{
  int arr[5] = {4,3,2,1,0,};
  int i = 0;
  printf("before sort: ");
  for(; i < 5; i++)
  {
    printf("%d ",arr[i]);
  }
   printf("\n");
      printf("after sort: ");
      quicksort(arr,0,4);
      for(i=0; i < 5; i++)
      {
          printf("%d ", arr[i]);
      }
      printf("\n");
      return 0;
  }             
