//Add all greater values to every node in a given BST

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

BSTree* insert(BSTree* root, int elem)
{
	if(root == nullptr)
		return newNode(elem);

	if(elem < root->data)
		root->left = insert(root->left, elem);
	else if(elem > root->data)
		root->right = insert(root->right, elem);

	return root;
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
void modifyBSTUtil(BSTree* root, int* sum)
{
	if(root == nullptr)
		return;

	modifyBSTUtil(root->right, sum);

	*sum = *sum + root->data;
	root->data = *sum;

	modifyBSTUtil(root->left, sum);
}

void modifyBST(BSTree* root)
{
	int sum = 0;
	modifyBSTUtil(root, &sum);
}

int main()
{
	BSTree* root = nullptr;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	//print inorder BST
	cout<<"Inorder BST:";
	print_inorder(root);

	modifyBST(root);
	cout<<"\nGreater Value added to BST:";
	print_inorder(root);

	cout<<endl;
	return 0;
}
