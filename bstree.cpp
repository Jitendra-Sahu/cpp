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

int main()
{
	BSTree* root = NULL;
	root = insert(root, 15);
	insert(root, 10);
	insert(root, 25);
	insert(root, 17);
	insert(root, 12);
	insert(root, 31);
	insert(root, 27);

	cout<<"\n Tree structure ---- ";
	print_inorder(root);
	cout<<endl;

	return 0;
}
