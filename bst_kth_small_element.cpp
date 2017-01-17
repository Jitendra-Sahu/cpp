//K’th smallest element in BST using O(1) Extra Space

#include<iostream>
#include<climits>

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

BSTree* insert(BSTree* root, int ref_data)
{
	if(root == nullptr)
		return newNode(ref_data);

	if(ref_data < root->data)
		root->left = insert(root->left, ref_data);
	else if(ref_data > root->data)
		root->right = insert(root->right, ref_data);

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

int KSmallestUsingMorris(BSTree* root, int k)
{
	int count = 0;

	int ksmall = INT_MIN;
	BSTree* curr = root;

	while(curr != nullptr)
	{
		if(curr->left == nullptr)
		{
			count++;
			if(count == k)
				ksmall = curr->data;
			curr = curr->right;
		}
		else
		{
			BSTree* pre = curr->left;
			while(pre->right != nullptr && pre->right != curr)
				pre = pre->right;
			if(pre->right == nullptr)
			{
				pre->right = curr;
				curr = curr->left;
			}
			else
			{
				pre->right = nullptr;
				count++;
				if(count == k)
					ksmall = curr->data;
				curr = curr->right;
			}
		}
	}
	return ksmall;
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

	cout<<"BST nodes are:\n";
	print_inorder(root);

	for(int k = 1; k <=7; ++k)
		cout<<"\n"<<KSmallestUsingMorris(root, k)<<" ";

	cout<<endl;

	return 0;
}
