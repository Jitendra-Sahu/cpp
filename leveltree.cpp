#include<iostream>
#include<queue>

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
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

BSTree* insert(BSTree* root, int data)
{
	if(root == NULL)
		return	newNode(data);

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

void level_order_traversal(BSTree* root)
{
	if(root == NULL)
		return;

	queue<BSTree*> q;
	q.push(root);

	while(!q.empty())
	{
		BSTree* current = q.front();
		cout<<current->data<<" ";
		if(current->left != NULL)
			q.push(current->left);
		if(current->right != NULL)
			q.push(current->right);
		q.pop();
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

	//print the tree
	cout<<"\n Tree element: ";
	print_inorder(root);
	cout<<endl;

	//print the tree in level order
	cout<<"\n Tree in level order: ";
	level_order_traversal(root);
	cout<<endl;

	return 0;
}

