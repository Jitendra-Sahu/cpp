//Lowest Common Ancestor in a Binary Search Tree
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
	temp->left = temp->right = NULL;

	return temp;
}

BSTree* insert(BSTree* root, int elem)
{
	if(root == NULL)
		return newNode(elem);

	if(elem < root->data)
		root->left = insert(root->left, elem);
	else if(elem > root->data)
		root->right = insert(root->right, elem);

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

BSTree* lca(BSTree* root, int n1, int n2)
{
	/*if(root == NULL)
		return NULL;

	if(root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);
	
	if(root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);
	*/
	while(root != NULL)
	{
		if(root->data > n1 && root->data > n2)
			root = root->left;
		else if(root->data < n1 && root->data < n2)
			root = root->right;
		else
			break;
	}
	return root;
}

int main()
{
	BSTree* root = NULL;
        root = insert(root, 20);
        insert(root, 8);
        insert(root, 22);
        insert(root, 4);
        insert(root, 12);
        insert(root, 10);
        insert(root, 14);

	//print the tree
	cout<<"\n Tree elements -- ";
	print_inorder(root);

	BSTree* temp = lca(root, 10, 14);
	cout<<"\n lca between 10 & 14 is - "<<temp->data;

	cout<<endl;
	return 0;
}
