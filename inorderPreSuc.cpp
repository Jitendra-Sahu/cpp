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

void findPreSuc(BSTree* root, BSTree*& pre, BSTree*& suc, int elem)
{
	if(root == NULL)
		return ;

	if(root->data == elem)
	{
		if(root->left != NULL)
		{
			BSTree* temp = root->left;
			while(temp->right)
				temp = temp->right;

			pre = temp;
		}
		
		if(root->right != NULL)
                {
                        BSTree* temp = root->right;
                        while(temp->left)
                                temp = temp->left;

                        suc = temp;
                }
	}
	
	if(elem < root->data)
	{
		pre = root;
		findPreSuc(root->left, pre, suc, elem);
	}
	else
	{
		suc = root;
		findPreSuc(root->right, pre, suc, elem);
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

	//print the predecessor & successor of one element
	int elem = 18;
	BSTree* pre = NULL;
	BSTree* suc = NULL;
	findPreSuc(root, pre, suc, elem);

	if(pre != NULL)
	{
		cout<<"\n predecessor : "<<pre->data<<endl;
	}
	else
	{
		cout<<"\n predecessor is NULL"<<endl;
	}

	if(suc != NULL)
	{
		cout<<"\n successor : "<<suc->data<<endl;
	}
	else
	{
		cout<<"\n successor is NULL"<<endl;
	}

	return 0;
}

