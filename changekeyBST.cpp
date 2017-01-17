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
	temp->left = temp->right = nullptr;

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

BSTree* delete_node(BSTree* root, int item)
{
	if(root == NULL)
		return root;

	if(item < root->data)
		root->left = delete_node(root->left, item);
	else if(item > root->data)
		root->right = delete_node(root->right, item);
	else
	{
		if((root->left == NULL) && (root->right == NULL))
		{
			delete (root);
			root = nullptr;
		}
		else if(root->left == NULL)
		{
			BSTree* temp = root;
			root = root->right;
			delete (temp);
		}
		else if(root->right == NULL)
		{
			BSTree* temp = root;
                        root = root->left;
			delete (temp);
		}
		else
		{
			BSTree* temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;
}		

BSTree* changeKey(BSTree* root, int oldValue, int newValue)
{
	root = delete_node(root, oldValue);

	root = insert(root, newValue);

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

	cout<<"Inorder traversal in BST: ";
	print_inorder(root);

	root = changeKey(root, 40, 10);
	
	cout<<"\nAfter change key from 40->10 : ";
	print_inorder(root);
	cout<<endl;
	return 0;
}
