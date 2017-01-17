//Print Common Nodes in Two Binary Search Trees

#include<iostream>
#include<stack>

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
	temp->left = temp->right = nullptr;
	
	return temp;
}

BSTree* insert(BSTree* root, int data)
{
	if(root == nullptr)
		return newNode(data);

	if(data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);

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

void printCommon(BSTree* root1, BSTree* root2)
{
	if(root1 == nullptr)
		return;
	stack<BSTree*> s1, s2;

	while(1)
	{
		if(root1)
		{
			s1.push(root1);
			root1 = root1->left;
		}
		else if(root2)
		{
			s2.push(root2);
			root2 = root2->left;
		}
		else if(!s1.empty() && !s2.empty())
		{
			root1 = s1.top();
			root2 = s2.top();
			if(root1->data == root2->data)
			{
				cout<<root1->data<<" ";
				root1 = root1->right;
				root2 = root2->right;

				s1.pop();
				s2.pop();
			}
			else if(root1->data < root2->data)
			{
				s1.pop();
				root1 = root1->right;
				root2 = nullptr;
			}
			else if(root1->data > root2->data)
			{
				s2.pop();
				root2 = root2->right;
				root1 = nullptr;
			}
		}
		else
			break;
	}
}

int main()
{
	// Create first tree
	BSTree *root1 = NULL;
	root1 = insert(root1, 5);
	root1 = insert(root1, 1);
	root1 = insert(root1, 10);
	root1 = insert(root1,  0);
	root1 = insert(root1,  4);
	root1 = insert(root1,  7);
	root1 = insert(root1,  9);
 
	// Create second tree
	BSTree *root2 = NULL;
	root2 = insert(root2, 10);
	root2 = insert(root2, 7);
	root2 = insert(root2, 20);
	root2 = insert(root2, 4);
	root2 = insert(root2, 9);
 
	cout << "Tree 1 : ";
	print_inorder(root1);
	cout << endl;
 
	cout << "Tree 2 : ";
	print_inorder(root2);
	cout<<endl;

	cout << "Common Node: ";
	printCommon(root1, root2);
	cout<<endl;

	return 0;
}
