//Check if each internal node of a BST has exactly one child

#include<iostream>

using namespace std;

bool hasOnlyOneChild(int pre[], int size)
{
	int nextDiff, lastDiff;

	for(int i=0; i < size-1; ++i)
	{
		nextDiff = pre[i] - pre[i+1];
		lastDiff = pre[i] - pre[size-1];
		if(nextDiff * lastDiff < 0)
			return false;
	}
	return true;
}

int main()
{
	int pre[] = {8, 3, 5, 7, 6};
	int size = sizeof(pre) /sizeof(pre[0]);
	if(hasOnlyOneChild(pre, size) == true )
		cout<<"BST all nodes have only one child\n";
	else
		cout<<"BST all nodes have more than one child\n";

	return 0;
}
