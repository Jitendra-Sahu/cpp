#include<iostream>

using namespace std;

class Tnode
{
	public:
		int data;
		Tnode* left;
		Tnode* right;
};

Tnode* newNode(int item)
{
	Tnode* temp = new Tnode();
	temp->data = item;
	temp->left = temp->right = NULL;
	
	return temp;
}

void print(Tnode* root, int k1, int k2)
{
	if(root == NULL)
		return;

	if(k1 < root->data)
		print(root->left, k1, k2);

	if(k1 <= root->data && k2 >= root->data)
		cout<<root->data<<" ";

	if(k2 > root->data)
		print(root->right, k1, k2);
}

int main()
{
	Tnode* root=NULL;
	int k1=10, k2=25;

	root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);

	//print the keys in between range
	cout<<"\n Keys in the range of 10 to 25 -> ";
	print(root, k1, k2);

	cout<<endl;
	return 0;
}
