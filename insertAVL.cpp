#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
		int height;
};

int max(int a, int b)
{
	return (a > b)? a:b;
}

int height(Node* root)
{
	if(root == nullptr)
		return 0;
	return(root->height);
}

Node* newNode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	temp->left = temp->right = nullptr;
	temp->height = 1;

	return temp;
}

Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->left))+1;

	return x;
}

Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

int getBalance(Node* node)
{
	if(node == NULL)
		return 0;
	return(height(node->left) - height(node->right));
}


Node* insert(Node* root, int key)
{
	if(root == nullptr)
		return newNode(key);

	if(key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);

	root->height = max(height(root->left), height(root->right))+1;
	int balance = getBalance(root);

	if(balance > 1 && key < root->left->data)
		return rightRotate(root);
	if(balance < -1 && key > root->right->data)
		return leftRotate(root);
	if(balance > 1 && key > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && key < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preOrder(Node* root)
{
	if(root != nullptr)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	Node* root = nullptr;
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	cout<<"PreOrder traversal in AVL tree: ";
	preOrder(root);

	cout<<endl;
	return 0;
}
