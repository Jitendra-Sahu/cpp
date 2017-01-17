//Top view of Binary search Tree

#include<iostream>

using namespace std;

class BSTree
{
	public:
		int data;
		BSTree* left;
		BSTree* right;
};

BSTree* newNode(int ref_data)
{
	BSTree* temp = new BSTree();
	temp->data = ref_data;
	temp->left = temp->right = nullptr;

	return temp;
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

static void top_view_post_order(BSTree* root)
{
	if(root == nullptr)
		return;
	top_view_post_order(root->left);
	cout<<root->data<<" ";
}

static void top_view_pre_order(BSTree* root)
{
        if(root == nullptr)
                return;
        cout<<root->data<<" ";
        top_view_pre_order(root->right);
}

void top_view(BSTree* root)
{
	BSTree* temp = root;
	if(root == nullptr)
		return;
	
	top_view_post_order(root);
	top_view_pre_order(root->right);
}

int main()
{
	BSTree* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);

	cout<<"Inorder traversal of BST: ";
	print_inorder(root);	

	cout<<"\nTop view nodes of BST: ";
	top_view(root);
	
	cout<<endl;
	return 0;
}
