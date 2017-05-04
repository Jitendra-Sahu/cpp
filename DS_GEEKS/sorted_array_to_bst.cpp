//Sorted Array to Balanced BST

#include<iostream>

using namespace std;

class BSTree
{
	public:
		int data;
		BSTree* left;
		BSTree* right;
};

BSTree* newNode(int data)
{
	BSTree* temp = new BSTree();
	temp->data = data;
	temp->left = temp->right = nullptr;

	return temp;
}

BSTree* insert(BSTree* root, int data)
{
	if(root == nullptr)
		return newNode(data);

	if (data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);

	return root;
}

void print_inorder(BSTree* root)
{
	if(root != nullptr)
	{
		print_inorder(root->left);
		cout<<root->data<<" ";
		print_inorder(root->right);
	}
}

BSTree* sorted_array_bst(int arr[], int start, int end)
{
	if( start > end)
		return nullptr;

	int mid = (start + end)/2;

	BSTree* root = newNode(arr[mid]);

	root->left = sorted_array_bst(arr, start, mid-1);
	root->right = sorted_array_bst(arr, mid+1, end);

	return root;
}

int main()
{
	BSTree* root = nullptr;
/*	root = insert(root, 12);
	insert(root, 7);
	insert(root, 14);
	insert(root, 4);
*/
	int arr[] = {1,2,3,4,5,6,7};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	root = sorted_array_bst(arr, 0, size);
	print_inorder(root);
	cout<<"\n";
	return 0;
}
