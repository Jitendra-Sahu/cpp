//Iterative Method to find Height of Binary Tree

#include<iostream>
#include<queue>

using namespace std;

class node
{
	public:
		int data;
		node* left;
		node* right;
};

node* newNode(int ref_data)
{
	node* temp = new node();
	temp->data = ref_data;
	temp->left = temp->right = nullptr;

	return temp;
}

int treeHeight(node* root)
{
	if(root == nullptr)
		return 0;

	queue<node*>q;
	q.push(root);
	int height = 0;

	while(1)
	{
		int nodeCount = q.size();
		if(nodeCount == 0)
			return height;

		height++;
		while(nodeCount > 0)
		{
			node* curr = q.front();
			q.pop();
			if(curr->left != nullptr)
				q.push(curr->left);
			if(curr->right != nullptr)
				q.push(curr->right);
			--nodeCount;
		}
	}
}

int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Height of tree is:"<<treeHeight(root)<<endl;

	return 0;
}
