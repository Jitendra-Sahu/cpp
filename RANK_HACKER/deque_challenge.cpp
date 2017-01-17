/*

Given a set of arrays of size  and an integer , you have to find the maximum integer for each and every contiguous subarray of size  for each of the given arrays.

Input Format

First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Constraints 
 
 
 
 , where  is the  element in the array .

Output Format

For each of the contiguous subarrays of size  of each array, you have to print the maximum integer.

Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
Sample Output

4 6 6 4
8 8 8 10
Explanation

For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. The 4 maximum elements of subarray of size 2 are: 4 6 6 4. 

For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.

*/

#include<iostream>
#include<deque>

using namespace std;

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
   //Write your code here.
   deque<int> deq;
   for(int i = 0; i < n; ++i)
   {
	deq.push_back(arr[i]);
   }

   int max = 0;
   for(int i = 0; i < n; ++i)
   {
   	for (int j = i+1; j < k && i < n; ++j)
   	{
		max = arr[i] > arr[j] ? arr[i] : arr[j];
		cout<< max <<" ";
    	}
   }
       /*for(int j = i+1; j < k; ++j )
       {
           if(arr[i] > arr[j])
               deq.push_back(arr[i]);
           else
               deq.push_back(arr[j]);
       }
   }
   while(!deq.empty())
   {
       int value = deq.back();
       cout<<value<<" ";
       deq.pop_back();
   }*/
}

int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
