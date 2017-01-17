//Binary Tree to Binary Search Tree Conversion

#include<iostream>

using namespace std;

class BSTree
{
	public:
		int data;
		BSTree* left;
		BSTree* right;
};

BSTree* newNode(int elem)
{
	BSTree* temp = new BSTree();
	temp->data = elem;
	temp->left = temp->right = nullptr;

	return temp;
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

int count_nodes(BSTree* root)
{
	if(root == nullptr)
		return 0;

	return count_nodes(root->left) + count_nodes(root->right) + 1;
}

void store_inorder(BSTree* root, int arr[], int* index_ptr)
{
	if(root == nullptr)
		return;

	store_inorder(root->left, arr, index_ptr);

	arr[*index_ptr] = root->data;
	(*index_ptr)++;

	store_inorder(root->right, arr, index_ptr);
}
	
void q_sort(int arr[], int low, int high)
{
	int i = low, j = high;
	int temp;
	int pivot = arr[(low+high)/2];

	while(j >= i)
	{
		while(arr[i] < pivot)
			++i;
		while(arr[j] > pivot)
			--j;
		if(i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
			--j;
		}				
	}
	if(low < j)
		q_sort(arr, low, j);
	if(i < high)
		q_sort(arr, i, high);
}

void arrayToBST(int* arr, BSTree* root, int* index_ptr)
{
	if(root == nullptr)
		return;

	arrayToBST(arr, root->left, index_ptr);

	root->data = arr[*index_ptr];
	(*index_ptr)++;

	arrayToBST(arr, root->right, index_ptr);
}

void binaryTreeToBST(BSTree* root)
{
	if(root == nullptr)
		return;

	int n = count_nodes(root);

	int* arr = new int[n];
	int i = 0;
	store_inorder(root, arr, &i);

	q_sort(arr, 0, n-1);
	cout<<"\nAfter sort: ";
	for(int k=0; k < n; ++k)
	{
		cout<<arr[k]<<" ";
	}

	i = 0;
	arrayToBST(arr, root, &i);

	delete []arr;
}

int main()
{
	BSTree* root = nullptr;
	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->right->right = newNode(5);

	cout<<"Following is the inorder traversal of BT:\n";
	print_inorder(root);

	binaryTreeToBST(root);
	cout<<"\nFollowing is the inorder traversal of converted BST:\n";
        print_inorder(root);

	cout<<endl;
	return 0;
}
