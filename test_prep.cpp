//Prep for any test
#include<iostream>
#include<queue>

using namespace std;

/* Complete BST operation
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
	{
		return newNode(data);
	}

	if(data < root->data)
		root->left = insert(root->left, data);
	else if(data > root->data)
		root->right = insert(root->right, data);

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

BSTree* findMin(BSTree* root)
{
	if(root == NULL)
		return root;
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

BSTree* delnode(BSTree* root, int elem)
{
	if(root == nullptr)
		return root;
	if(elem < root->data)
		root->left = delnode(root->left, elem);
	else if(elem > root->data)
		root->right = delnode(root->right, elem);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = nullptr;
		}
		else if(root->left == NULL)
		{
			BSTree* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			BSTree* temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			BSTree* temp = findMin(root->right);
			root->data = temp->data;
			root->right = delnode(root->right, temp->data);
		}
	}
	return root;
}

void level_order_traversal(BSTree* root)
{
	if(root == NULL)
		return;

	queue<BSTree*> q;
	q.push(root);

	while(!q.empty())
	{
		BSTree* current = q.front();
		cout<<current->data<<" ";
		if(current->left != NULL)
			q.push(current->left);
		if(current->right != NULL)
			q.push(current->right);

		q.pop();
	}
}

int main()
{
	BSTree* root = nullptr;
	root = insert(root, 40);
	insert(root, 10);
	insert(root, 25);
	insert(root, 17);
	insert(root, 12);
	insert(root, 31);
	insert(root, 27);

	cout<<"Inorder traversal in BST:";
	print_inorder(root);

	int del_node = 17;
	delnode(root, del_node);
	cout<<"\nInorder traversal in BST after delete:";
	print_inorder(root);

	cout<<"\n Level order traversal:";
	level_order_traversal(root);

	cout<<endl;
	return 0;
}
*/

/* Stack all operation
class MyStack
{
	public:
		MyStack();
		MyStack(int size);
		~MyStack();
		void push(int data);
		int pop();
		bool empty();
		void display();
	private:
		int* pdata;
		int top, length;
};

MyStack::MyStack()
{
	top = 0;
	length = 0;
	pdata = 0;
}		

MyStack::MyStack(int size)
{
	length = size;
	top = -1;
	if(size == 0)
	{
		pdata = 0;
	}
	else
		pdata = new int[length];
}		

MyStack::~MyStack()
{
	delete []pdata;
}

void MyStack::push(int data)
{
	if(pdata == 0)
	{
		cout<<"Stack is empty, please enter size:";
		cin>>length;
		pdata = new int[length];
	}
	if(top == (length-1))
	{
		cout<<"\nCan't push data "<<data<<" ,as stack is full\n";
		return;
	}
	else
	{
		++top;
		pdata[top] = data;
	}
}

bool MyStack::empty()
{
	if(top == -1 || (pdata == 0))
		return true;
	else
		return false;
}

int MyStack::pop()
{
	if(top == -1 || (pdata == 0))
	{
		return -1;
	}
	else
	{
		int temp = pdata[top];
		--top;
		return temp;
	}
}	

void MyStack::display()
{
	for(int i = 0; i <= length; i++)
		cout<<pdata[i]<<" ";

	cout<<endl;
}

int main()
{
MyStack s1;
        s1.push(1);
    s1.display(); 
    s1.push(2); 
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();

	return 0;
}
*/

/* Customized String Class
class MyString
{
	public:
		MyString();
		MyString(const char* input);
		MyString(const MyString& s);
		~MyString();
		int length();
		bool empty();
		char& at(int loc);

		MyString& operator=(const MyString& s);
		friend bool operator ==(const MyString& s1, const MyString& s2);
		friend MyString operator+(const MyString& s1, const MyString& s2);
		friend ostream& operator <<(ostream& OS, MyString& s);
	private:
		char* nstring;
		short nlength;
};

MyString::MyString()
{
	nlength = 0;
	nstring = new char[nlength + 1];
	nstring[nlength] = '\0';
}

MyString::MyString(const char* input)
{
	nlength = strlen(input);
	nstring = new char[nlength + 1];
	for(int i = 0; i < nlength; ++i)
	{
		nstring[i] = input[i];
	}
	if(nstring[nlength] != '\0')
		nstring[nlength] = '\0';
}

MyString::MyString(const MyString& s)
{
	nlength = s.nlength;
	nstring = new char[nlength + 1];
	for(int i = 0; i < nlength; ++i)
        {
		nstring[i] = s.nstring[i];
	}
	if(nstring[nlength] != '\0')
                nstring[nlength] = '\0';
}

MyString::~MyString()
{
	delete []nstring;
}

int MyString::length()
{
	int count = 0;
	while(nstring[count] != '\0')
	{
		++count;
	}
	return count;
}

char& MyString::at(int loc)
{
	return nstring[loc-1];
}

bool MyString::empty()
{
	if(nstring[0] == '\0' && nlength == 1)
		return true;
	else
		return false;
}

MyString& MyString::operator =(const MyString& s)
{
	nlength = s.nlength;
	nstring = new char[nlength + 1];
	for(int i = 0; i < nlength; ++i)
	{
		nstring[i] = s.nstring[i];
	}
	if(nstring[nlength] != '\0')
		nstring[nlength] = '\0';

	return *this;
}

ostream& operator <<(ostream& OS, MyString& s)
{
	OS<<s.nstring;
	return OS;
}

bool operator ==(const MyString& s1, const MyString& s2)
{
	int count = 0;
	if(s1.nlength == s2.nlength)
	{
		for(int i = 0; i < s1.nlength; ++i)
		{
			if(s1.nstring[i] != s2.nstring[i])
				++count;
		}
		if(count != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}

MyString operator +(const MyString& s1, const MyString& s2)
{
	int size = s1.nlength + s2.nlength;
	char* temp = new char[size + 1];
	for(int i = 0; i < s1.nlength; ++i)
	{
		temp[i] = s1.nstring[i];
	}
	
	for(int k = s1.nlength, j = 0; k < size; ++k,++j)
	{
		temp[k] = s2.nstring[j];
	} 

	if(temp[size] != '\0')
		temp[size] = '\0';
	
	MyString s3;
	s3.nlength = size;
	s3  = new char[size+1];
	for(int i = 0; i < size; ++i)
	{
		s3.nstring[i] = temp[i];
	}
	if(s3.nstring[size] != '\0')
		s3.nstring[size] = '\0';
	
	return s3;
	delete []temp;
}

int main()
{       
        MyString A("def");
        MyString B("abc");
        cout<<B<<endl;
        MyString C = A + B;
        cout<<C<<endl;
        
        return 0;
}
*/

/* Singly linked list all operation
class node
{
	public:
		int data;
		node* next;
};

//node* head = NULL;

void insert(node** head, int elem)
{
	node* temp = new node();
	temp->data = elem;
	temp->next = *head;
	*head = temp;
}

void push(node** head, int elem, int pos)
{
	node* temp1 = new node();
	temp1->data = elem;
	temp1->next = nullptr;
	if(pos == 1)
	{
		temp1->next = *head;
		*head = temp1;
		return;
	}
	node* temp2 = *head;
	for(int i = 0; i <pos-2; ++i)
		temp2 = temp2->next;

	temp1->next = temp2->next;
	temp2->next = temp1;
}

void print_list(node* head)
{
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void reverse(node **head)
{
	node* current = *head;
	node* prev = nullptr;
	node* nxt;
	while(current != nullptr)
	{
		nxt = current->next;
		current->next = prev;
		prev = current;
		current = nxt;
	}
	*head = prev;
}

void delnode(node** head, int n)
{
	node* temp1 = *head;
	if(n == 1)
	{
		*head = temp1->next;
		delete temp1;
		return;
	}
	
	for(int i =0; i < n-2; ++i)
		temp1 = temp1->next;

	node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}

int main()
{
	node* head = nullptr;
//	insert(&head, 12);
//	insert(&head, 16);
//	insert(&head, 1);
//	insert(&head, 5);
//	insert(&head, 17);
	push(&head,1,1);
	push(&head,5,2);
	push(&head,12,3);
	push(&head,16,4);
	push(&head,17,5);

	cout<<"Linked list from head:";
	print_list(head);

	cout<<"Reverse the List:";
	reverse(&head);
	print_list(head);

	cout<<"After delete 4th node:";
	delnode(&head, 4);
	print_list(head);

	return 0;
}
*/

//Binary search & quick sort
int bin_search(int arr[], int low, int high, int elem)
{
	if(low > high)
		return -1;

	int mid = (low+high)/2;

	if(arr[mid] == elem)
	{
		return mid;
	}
	else if(elem > arr[mid])
	{
		return bin_search(arr, mid+1, high, elem);
	}
	else
	{
		return bin_search(arr, low, mid-1, elem);
	}
}

//quick sort
void sort(int arr[], int low, int high)
{
	int i = low, j = high;
	int temp;
	int pivot = arr[(low + high)/2];

	while(j >= i)
	{
		while(arr[i] < pivot)
			++i;
		while(arr[j] > pivot)
			--j;
		if(i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if(low < j)
		sort(arr, low, j);						
	if(i < high)
		sort(arr, i, high); 
}

int main()
{
	int arr[] = {11, -4, 9, 43, 5, 485, 8};
        int n = sizeof(arr)/sizeof(arr[0]);
        int key = 11;
        int low = 0;
        int high =n-1;

	sort(arr, low, high);
	cout<<"Sorted array:";
	for(int i =0; i < n ; ++i)
		cout<<arr[i]<<" ";

	int index = bin_search(arr, low, high, key);
	cout<<"\n"<<key<<" found @pos with binary search:"<<index+1<<endl;

	return 0;
}	
		
