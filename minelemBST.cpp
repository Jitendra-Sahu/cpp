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

BSTree* insert(BSTree* root, int data)
{
	if(root == NULL)
		return newNode(data);

	if(data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);

	return root;
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

int minValue(BSTree* root)
{
	if(root == NULL)
		return 0;

	BSTree* cur = root;
	while(cur->left != NULL)
		cur = cur->left;

	return(cur->data);
}

int main()
{
	BSTree* root = NULL;
	root = insert(root, 4);
  	insert(root, 2);
  	insert(root, 15);
  	insert(root, 3);
  	insert(root, 6);
  	insert(root, 5);

	cout<<"\n BST......."<<endl;
	print_inorder(root);

	//Min element in BST
	int min_elem = minValue(root);
	cout<<"\n Min value element: "<<min_elem;
	cout<<endl;
	return 0;
}
