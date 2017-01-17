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
	else if(item > root->data)
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

BSTree* minValue(BSTree* root)
{
	BSTree* current = root;

	while(current->left != NULL)
		current = current->left;

	return current;
}

BSTree* inOrderSuccessor(BSTree* root, BSTree* node)
{
	if(node->right != NULL)
		return minValue(node->right);

	BSTree* succ = NULL;

	while(root != NULL)
	{
		if(node->data < root->data)
		{
			succ = root;
			root = root->left;
		}
		else if(node->data > root->data)
			root = root->right;
		else
			break;
	}

	return succ;
}

int main()
{
	BSTree* root = NULL;
	BSTree* temp = NULL;
	BSTree* succ = NULL;
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);  
	root = insert(root, 14);

	cout<<"\n BST look like --";
	print_inorder(root);

	//temp = root->left->right->right; 
	temp = root->left;
	succ =  inOrderSuccessor(root, temp);

	if(succ != NULL)
		cout<<"\n Inorder Successor of "<<temp->data<<" is: "<<succ->data;
	else
		cout<<"\n Inorder Successor doesn't exit";

	cout<<endl;
	return 0;
}
