#include<iostream>

using namespace std;

class Tnode
{
	public:
		int data;
		Tnode* left;
		Tnode* right;
};

Tnode* newNode(int item)
{
	Tnode* temp = new Tnode();
	temp->data = item;
	temp->left = temp->right = NULL;

	return temp;
}

void print_preorder(Tnode* root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	print_preorder(root->left);
	print_preorder(root->right);
}

Tnode* sortedArrayToBST(int arr[], int start, int end)
{
	if(start > end)
		return nullptr;

	int mid = (start + end) / 2;
	Tnode* root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start, mid-1);

	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int arr_len = sizeof(arr)/sizeof(arr[0]);

	//converting sorted array to BST
	Tnode* root = sortedArrayToBST(arr, 0, arr_len-1);
	
	//print the BST
	cout<<"\n BST from array---> ";
	print_preorder(root);

	cout<<endl;
	return 0;
}
	
