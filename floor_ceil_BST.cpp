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
	if(root != NULL)
	{
		print_inorder(root->left);
		cout<<root->data<<" ";
		print_inorder(root->right);
	}
}

int ceil(BSTree* root, int input)
{
	if(root == NULL)
		return -1;

	if(root->data == input)
		return root->data;
	
	if(input > root->data)
		return ceil(root->right, input);

	int ceil_val = ceil(root->left, input);
	return (ceil_val >= input) ? ceil_val : root->data;
}

int main()
{
	BSTree* root = newNode(8);
	root->left = newNode(4);
	root->right = newNode(12);
 
	root->left->left = newNode(2);
	root->left->right = newNode(6);
 
	root->right->left = newNode(10);
	root->right->right = newNode(14);

	cout<<"BSTree look like....\t";
	print_inorder(root);

	//Ceil value
	cout<<"\nCeil vaules are...\n";
	for(int i=0; i < 16; ++i)
	{
		int ceil_val = ceil(root, i);
		cout<<i<<" "<<ceil_val<<"\n";
	}
	cout<<endl;
	return 0;
}
	
