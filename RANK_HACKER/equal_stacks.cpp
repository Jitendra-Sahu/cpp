/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. The removals must be performed in such a way as to maximize the height.
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(){
    int ss1 = 0, ss2 = 0, ss3 = 0;
    cin >> ss1 >> ss2 >> ss3;

	vector< queue<int> > ss;
	vector<int>height;

	for (int n = 0; n < 3; n++) {
		ss.push_back(queue<int>());
	}
	for (int n = 0; n < 3; n++) {
		height.push_back(0);
	}

	int temp = 0;

	for (int i = 0; i < ss1; i++) {
		cin >> temp;
		ss[0].push(temp);
		height[0] += temp;
	}
	for (int i = 0; i < ss2; i++) {
		cin >> temp;
		ss[1].push(temp);
		height[1] += temp;
	}
	for (int i = 0; i < ss3; i++) {
		cin >> temp;
		ss[2].push(temp);
		height[2] += temp;
	}

	vector<int>::iterator max;
	int max_i = 0;

	while ((height[0] != height[1]) || (height[1] != height[2])) 
    	{
		max = max_element(height.begin(), height.end());
		max_i = distance(height.begin(), max);
		height[max_i] -= ss[max_i].front();
		ss[max_i].pop();
	}
	cout << height[0]<<endl;
    
    return 0;
}

