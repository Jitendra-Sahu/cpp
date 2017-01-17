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

void secondlargest_1(BSTree* root)
{
	if(root == NULL)
		return;

	BSTree* current = root;
	BSTree* temp;

	while(current->right != NULL)
	{
		temp = current;
		current = current->right;
	}

	cout<<"\n 2nd largest elem: "<<temp->data;
}

void secondlargestutil(BSTree* root, int &c)
{
	if(root == NULL || c >= 2)
		return;

	secondlargestutil(root->right, c);
	++c;

	if(c == 2)
	{
		cout<<"\n 2nd largest elem: "<<root->data;
		return ;
	}

	secondlargestutil(root->left, c);
}
	
void secondlargest_2(BSTree* root)
{
	int c=0;
	secondlargestutil(root, c);
}

int main()
{
	BSTree* root = newNode(50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	insert(root, 90);

	cout<<"BST look like ...";
	print_inorder(root);

	secondlargest_1(root);
	secondlargest_2(root);

	cout<<endl;
	return 0;
}
