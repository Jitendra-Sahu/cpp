//Two nodes of a BST are swapped, correct the BST

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

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void correctBSTUtil(BSTree* root, BSTree** first, BSTree** middle, BSTree** last,  BSTree** prev)
{
	if(root)
	{
		correctBSTUtil(root->left, first, middle, last, prev);
		if(*prev && root->data < (*prev)->data)
		{
			if(!*first)
			{
				*first = *prev;
				*middle = root;
			}
			else
				*last = root;
		}
		*prev = root;
		correctBSTUtil(root->right, first, middle, last, prev);
	}	
}

void correctBST(BSTree* root)
{
	BSTree* first;
	BSTree* middle;
	BSTree* last; 
	BSTree* prev;
	first = middle = last = prev = nullptr;

	correctBSTUtil(root, &first, &middle, &last, &prev);

	if(first && last)
		swap(&(first->data), &(last->data));
	else if(first && middle)
		swap(&(first->data), &(middle->data));
}

int main()
{
	BSTree* root = newNode(6);
	root->left = newNode(10);
	root->right = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);

	cout<<"Inorder traversal of original tree:";
	print_inorder(root);

	cout<<"\nInorder traversal of fixed tree:";
	correctBST(root);
	print_inorder(root);

	cout<<endl;
	return 0;
}	
