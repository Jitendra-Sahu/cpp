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
	temp->left = temp->right = NULL;
	return temp;
}

BSTree* insert(BSTree* root, int item)
{
	if(root == NULL)
		return newNode(item);

	if(item < root->data)
		root->left = insert(root->left, item);

	if(item > root->data)
		root->right = insert(root->right, item);

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

bool search(BSTree* root, int elem)
{
	if(root == NULL)
		return false;

	if(elem == root->data)
		return true;
	else if(elem < root->data)
		return search(root->left, elem);
	else
		return search(root->right, elem);
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

	//print the tree
	cout<<"\n Tree element: ";
	print_inorder(root);
	cout<<endl;

	//search an element
	int elem = 18;
	bool res;
	res = search(root, elem);
	if(res)
		cout<<"\n search success"<<endl;
	else
		cout<<"\n search unsuccess"<<endl;

	return 0;
}

