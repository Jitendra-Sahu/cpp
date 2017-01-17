//Swap nodes in binary tree

#include<iostream>
#include<vector>

using namespace std;

struct Node { int left, right; };

void swapRec(vector<Node>& tree, int k, int lvl, int cur)
{
    	if (cur==-2) return;
    	if (lvl%k==0) swap(tree[cur].left,tree[cur].right);
    	swapRec(tree,k,lvl+1,tree[cur].left);
    	swapRec(tree,k,lvl+1,tree[cur].right);
}

void printInOrder(const vector<Node>& tree, int cur)
{
    	if (cur==-2) return;
   	 printInOrder(tree,tree[cur].left);
    	cout<<cur+1<<' ';
    	printInOrder(tree,tree[cur].right);
}

int main()
{
	unsigned int n; cin>>n;
    vector<Node> tree; tree.reserve(n);
    for (unsigned int i = 0; i<n; ++i)
        tree.push_back([]{ int a, b; cin>>a>>b; return Node{a-1,b-1}; }());
    unsigned int t; cin>>t; 
    for (unsigned int i = 0; i<t; ++i)
    {
        int k; cin>>k;
        swapRec(tree,k,1,0);
        printInOrder(tree,0), cout<<'\n';
    }
    return 0;
}

	
	
