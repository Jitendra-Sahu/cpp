#include<stdio.h>

void rvereseArray(int arr[], int start, int end)
{
  int temp;
  while(start < end)
  {
    temp = arr[start];   
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }   
}     
 
/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
 
  printf("\n");
} 
 
/* Driver function to test above functions */
int main() 
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  printArray(arr, 6);
  rvereseArray(arr, 0, 5);
  printf("Reversed array is \n");
  printArray(arr, 6);
  //getchar();
  return 0;
}
