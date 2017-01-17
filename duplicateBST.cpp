#include<iostream>

using namespace std;

class BSTree
{
	public:
		int data;
		int count;
		BSTree* left;
		BSTree* right;
};

BSTree* newNode(int item)
{
	BSTree* temp = new BSTree();
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->count = 1;

	return temp;
}

BSTree* insert(BSTree* root, int item)
{
	if(root == NULL)
		return newNode(item);

	if(item == root->data)
	{
		++(root->count);
		return root;
	}

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
		cout<<root->data<<"("<<root->count<<")"<<" ";
		print_inorder(root->right);
	}
}

BSTree* minValueNode(BSTree* root)
{
	BSTree* current = root;
	
	while(current->left != NULL)
		current = current->left;

	return current;
}

BSTree* delete_node(BSTree* root, int key)
{
	if(root == NULL)
		return root;

	if(key < root->data)
		root->left = delete_node(root->left, key);
	else if(key > root->data)
		root->right = delete_node(root->right, key);
	else
	{
		if(root->count > 1)
		{
			--(root->count);
			return root;
		}
		if(root->left == NULL)
		{
			BSTree* temp = root->right;
			delete(root);
			return temp;
		}
		else if(root->right == NULL)
                {
                        BSTree* temp = root->left;
                        delete(root);
                        return temp;
                }

		BSTree* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}
		

int main()
{
	BSTree* root = NULL;
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 9);
	root = insert(root, 11);
	root = insert(root, 10);
	root = insert(root, 12);
	root = insert(root, 12);

	cout<<"BSTree come up like this... where node with count...\n";
	print_inorder(root);

	//delete one node
	cout<<"Delete the node 20\n";
	root = delete_node(root, 20);

	print_inorder(root);

	cout<<endl;
	return 0;
}
		
