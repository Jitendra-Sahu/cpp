#include<iostream>
#include<cstring>

using namespace std;

class MyString
{
	public:
		MyString(void);
		MyString(const char* input);
		MyString(const MyString& s);
		~MyString();
		
		int length();
		char& at(int loc);
		bool empty();
		void swap(MyString& from);
		int find(const MyString& s, int index=0);
		
		MyString& operator=(const MyString& s);
		friend bool operator ==(const MyString& s1, const MyString& s2);
		friend MyString operator +(const MyString& s1, const MyString& s2);
	
		friend ostream& operator << (ostream & OS, MyString& S)
		{
			OS<<S.nstring;
			return OS;
		}
	private:
		char* nstring;
		short nlength;
};

MyString::MyString()
{
	nlength = 1;
	nstring = new char[nlength];
	nstring[nlength] = '\0';
}

MyString::MyString(const char* input)
{
	nlength = strlen(input);
	nstring = new char[nlength + 1];
	for(int i = 0; i < nlength; ++i)
		nstring[i] = input[i];
	nstring[nlength] ='\0';
}

MyString::MyString(const MyString& s)
{
	nlength = s.nlength;
	nstring = new char[nlength + 1];
	for(int i = 0; i < nlength; ++i)
		nstring[i] = s.nstring[i];
	if(nstring[nlength - 1] != '\0')
	{
		nstring[nlength - 1] ='\0';
	}
}

MyString::~MyString()
{
	delete []nstring;
}

int MyString::length()
{
	int i = 0;
	while(nstring[i] != '\0')
	{
		++i;
	}
	return i;
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

void MyString::swap(MyString& from)
{
}

MyString& MyString::operator = (const MyString& s)
{
	nlength = s.nlength;
	delete []nstring;
	nstring = new char[nlength+1];
	for(int i = 0; i < nlength; ++i)
	{
		nstring[i] = s.nstring[i];
	}
	nstring[nlength] = '\0';
	return *this;
}

MyString operator + (const MyString& s1, const MyString& s2)
{
	int size = s1.nlength + s2.nlength;
	char *temp = new char[size];
	for(int i = 0; i < (s1.nlength); ++i)
	{
		temp[i] = s1.nstring[i];
	}
	
	int j = 0;
	for(int k = s1.nlength, j = 0; k < (size); ++j, ++k)
	{
		temp [k] = s2.nstring[j];
	}
	if(temp[size - 1] != '\0')
	{
		temp[size] ='\0';
	}

	MyString s3;
	s3.nlength = size;
	delete []s3.nstring;
	s3.nstring = new char[size];
	for(int z=0; z < (size); ++z)
	{
		s3.nstring[z] = temp[z];
	}
	if(s3.nstring[size-1] != '\0')
	{
		s3.nstring[size] = '\0';
	}

	return s3;
	delete []temp;
}

bool operator == (const MyString& s1, const MyString& s2)
{
	if(s1.nlength == s2.nlength)
	{
		short counter1 = s1.nlength;
		int counter2 = 0;
		int i = 0;
		while(i != counter1)
		{
			if(s1.nstring[i] != s2.nstring[i])
			{
				++counter2;
			}
			++i;
		}
		if(counter2 != 0)
			return false;
		else
			return true;
	}
	else
		return false;
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
