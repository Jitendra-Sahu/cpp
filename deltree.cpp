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

BSTree* findMin(BSTree* root)
{
	if(root == NULL)
		return root;

	BSTree* current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

BSTree* deleteNode(BSTree* root, int elem)
{
	if(root == NULL)
		return root;

	if(elem < root->data)
		root->left = deleteNode(root->left, elem);
	else if(elem > root->data)
		root->right = deleteNode(root->right, elem);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root->left == NULL)
		{
			BSTree* temp = root;
			root = root->right;
			delete(temp);
		}
		else if(root->right == NULL)
		{
			BSTree* temp = root;
			root = root->left;
			delete(temp);
		}
		else
		{
			BSTree* temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

int main()
{
	BSTree* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	//print the tree
	cout<<"\n Tree --- ";
	print_inorder(root);
	
	//delete one node
	int del_elem = 60;
	root = deleteNode(root, del_elem);

	//print the tree after delete
        cout<<"\n Tree after delete 60---";
        print_inorder(root);

	cout<<endl;

	return 0;
}
