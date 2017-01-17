//Calculate the hourglass sum for every hourglass in , then print the maximum hourglass sum.

/*
Context 
Given a  2D Array, :

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
We define an hourglass in  to be a subset of values with indices falling in this pattern in 's graphical representation:

a b c
  d
e f g
There are  hourglasses in , and an hourglass sum is the sum of an hourglass' values.
*/

#include<iostream>
#include<vector>
#include <climits>

#define SIZE 6
#define SIZE_GLASS 3

using namespace std;

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    int max = INT_MIN;
    for(int arr_i = 0; arr_i<SIZE-SIZE_GLASS+1; arr_i++){
       for(int arr_j=0; arr_j<SIZE-SIZE_GLASS+1; arr_j++){
           int sum = 0;
           for(int x=arr_j; x<arr_j+SIZE_GLASS; x++)
               sum += arr[arr_i][x];
           for(int x=arr_j; x<arr_j+SIZE_GLASS; x++)
               sum += arr[arr_i+SIZE_GLASS-1][x];
           sum += arr[arr_i+1][arr_j+1];

           if(sum>max){
               max = sum;
           }
       }
    }
    cout << max;
    return 0;
}

