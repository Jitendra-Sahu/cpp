//Write a function which takes an array and emits the majority element (if it exists), otherwise prints NONE
//A majority element in an array A[] of size n is an element that appears more than n/2 times

//Date :Thu Oct 15 15:18:51 IST 2015

#include<iostream>

using namespace std;

int main()
{
   int arr[]={3,3,4,2,4,4,2,4,4};
   //int arr[]={3,3,3,3,4,4,4,4,4,4};
   int len = sizeof(arr)/sizeof(arr[0]);

   int i, j, num;
   for(i = 0; i < len; i++)
   {
        /* Below logic work with sorted array
	j = i;
        int count = 0;
	while((arr[j] == arr[i]) && j < len){
        ++count;
        ++j;
	}
     if(count > (len/2))
     {
     	cout<<arr[i]<<" Number has "<<count<<" times\n";
     	return 0;
     }
     else
     {
        count = 0;
	i = j - 1;
     }*/

     //This O(n * n) work for all cases
     /*int count = 0;
     for(j = 0; j < len; j++)
     {
       if(arr[i] == arr[j])
       {
         ++count;
       }
     }
     if(count > (len/2))
     {
     	cout<<arr[i]<<" Number has "<<count<<" times\n";
     	return 0;
     }*/
   }
   cout<<"\nBaba ji ka THULLU\n";

   return 0;
}

   
