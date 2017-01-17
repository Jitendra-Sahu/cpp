// write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x
// Date : Thu Oct 15 10:14:52 IST 2015

#include<iostream>

using namespace std;


void Array_Sort(int A[], int len)
{
   //insertion sort
   int i, key, j;
   for (i = 1; i < len; i++)
   {
       key = A[i];
       /* Move elements of A[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       for(j = i-1; j >=0 && key < A[j]; j--)
       {
            A[j+1] = A[j];
       }
       A[j+1] = key;
    }
}

bool Has_Array_Two_Elements(int A[], int len, int sum)
{
   bool res = false;	
   for(int i = 0 ; i < len; i++)
   {
     for(int j = i+1 ; j < len; j++)
     {
       if((A[i] + A[j]) == sum )
       {
         res = true;
         break;
       }
     }
   }
   return res;
}

void Print_Array(int A[], int len)
{
  cout<<"\nArray element: ";
  for(int i = 0; i < len; i++)
  {
    cout<<A[i]<<" ";
  }
}

int main()
{
  int A[] = {1, 4, 45, 6, 10, -8};
  int sum = 7;
  int len = sizeof(A)/sizeof(A[0]);

  cout<<"Length of array: "<<len;
  Print_Array(A, len);

  //Sorting the array
  Array_Sort(A, len);
  cout<<"\nAfter sort: ";
  Print_Array(A, len);

  //Find two elements
  if(Has_Array_Two_Elements(A, len, sum))
  {
    cout<<"\nArray has two elements sum of"<< sum;
  }
  else
  {
    cout<<"\nArray doesn't have two elements with sum "<<sum;
  }

  cout<<"\n";
  return 0;
}

