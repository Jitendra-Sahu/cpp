#include<iostream>
#include<limits.h>

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

int isBSTUtil(BSTree* root, int min, int max)
{
	if(root == NULL)
		return 1;
	
	if(root->data < min || root->data > max)
		return 0;

	return(isBSTUtil(root->left, min, (root->data)-1)) &&
		(isBSTUtil(root->right, (root->data)+1, max));
}

int isBST(BSTree* root)
{
	return(isBSTUtil(root, INT_MIN, INT_MAX));
}

/*
bool isBST(BSTree* root)
{
    static BSTree* prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}
*/

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
	BSTree* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->right->right = newNode(3);

	//print the tree
	print_inorder(root);

	if(isBST(root))
	{
		cout<<"\n This is BST"<<endl;
	}
	else
	{
		cout<<"\n Not BST"<<endl;
	}

	return 0;
}	
