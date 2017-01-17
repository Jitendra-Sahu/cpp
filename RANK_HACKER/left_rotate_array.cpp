/*Function to left Rotate arr[] of size n by 1*/
#include<stdio.h>
#include<iostream>

using namespace std;

void leftRotatebyOne(int arr[], int n);
 
/*
void leftRotate(int arr[], int d, int n)
{
  int i;
  for (i = 0; i < d; i++)
    leftRotatebyOne(arr, n);
}
 
void leftRotatebyOne(int arr[], int n)
{
  int i, temp;
  temp = arr[0];
  for (i = 0; i < n-1; i++)
     arr[i] = arr[i+1];
  arr[i] = temp;
}
 
void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
}
 
int main()
{
   int size, d;
   cin>>size>>d;
   int arr[size] ;
    for(int i=0; i< size; ++i)
    {
	cin>>arr[i];
    } //= {1, 2, 3, 4, 5, 6, 7};
    for(int i=0; i< d; ++i)
    {
	leftRotatebyOne(arr, size);
    }
   //leftRotate(arr, 2, 7);
   printArray(arr, 7);
   getchar();
   return 0;
}*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*void left_rotate_array(int arr[], int size)
{
    int i, temp;
    temp = arr[0];
    for(i = 0; i < size-1; ++i)
    {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}*/

int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

/*Function to left rotate arr[] of siz n by d*/
void left_rotate_array(int arr[], int d, int n)
{
  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); i++)
  {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, d, temp, j;
    cin>>n>>d;
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    //for(int i = 0; i < d; ++i)
    //{ 
        left_rotate_array(arr, d, n);
    //}
    for(int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

