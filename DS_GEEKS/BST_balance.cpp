//determine if a binary tree is height-balanced?

#include<iostream>
#include<stdlib.h>

using namespace std;

class BSTree
{
	public:
		int data;
		BSTree* left;
		BSTree* right;
};

int height(BSTree* root);

bool is_balance(BSTree* root)
{
	if(root == nullptr)
		return true;

	int l_height = height(root->left);
	int r_height = height(root->right);

	if(abs(l_height - r_height) <= 1 &&
	   is_balance(root->left) && 
	   is_balance(root->right))
	{
		return true;
	}

	return false;
}

int max(int a, int b)
{
	return (a >= b)? a:b;
}

int height(BSTree* root)
{
	if(root == nullptr)
		return 0;
	return (1+max(height(root->left), height(root->right)));
}

BSTree* newNode(int data)
{
	BSTree* temp = new BSTree();
	temp->data = data;
	temp->left = temp->right = nullptr;
	return temp;
}

int main()
{
	BSTree* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);

	if(is_balance(root))
		cout<<"\nBST is balanced\n";
	else
		cout<<"\nBST is not balanced\n";

	return 0;
}
