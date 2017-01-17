#include<iostream>

using namespace std;

class BSTree
{
	public:
		int data;
		BSTree* left;
		BSTree* right;
};

BSTree* newNode(int item)
{
	BSTree* temp = new BSTree();
	temp->data = item;
	temp->left = temp->right = NULL;

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

BSTree* constructTreeUtil(int arr[], int* preIndex, int low, int high, int size)
{
	if(*preIndex >= size || low > high)
		return nullptr;

	BSTree* root = newNode(arr[*preIndex]);
	*preIndex = *preIndex + 1;

	if(low == high)
		return root;

	int i;
	for(i = low; i <= high; ++i)
		if(arr[i] > root->data)
			break;

	root->left = constructTreeUtil(arr, preIndex, *preIndex, i-1, size);
	root->right = constructTreeUtil(arr, preIndex, i, high, size);

	return root;
}

BSTree* constructTree(int arr[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(arr, &preIndex, 0, size-1, size);
}

int main()
{
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(pre) / sizeof(pre[0]);

	BSTree* root = constructTree(pre, size);

	cout<<"Inorder traversal of the constructed tree:";
	print_inorder(root);

	cout<<endl;
	return 0;
}
	
