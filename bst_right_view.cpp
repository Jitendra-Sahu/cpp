//Print Right View of a Binary Tree

#include<iostream>

using namespace std;

class BSTree
{
	public:
		int data;
		BSTree* left;
		BSTree* right;
};

BSTree* newNode(int ref_data)
{
	BSTree* temp = new BSTree();
	temp->data = ref_data;
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

void right_view(BSTree* root)
{
	if(root == nullptr)
		return;
	cout<<root->data<<" ";
	right_view(root->right);
}

int main()
{
	BSTree* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->right = newNode(8);

	cout<<"Inorder traversal of binary tree: ";
	print_inorder(root);

	cout<<"\nRight view of of binary tree: ";
	right_view(root);

	cout<<endl;
	return 0;
}
