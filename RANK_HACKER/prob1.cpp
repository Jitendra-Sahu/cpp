
/*
#include<iostream>


using namespace std;

int main() {
    int m,i=0,j,up,down,a[10];
    long int n, s;
    cin>>m;
    for(int k = 1; k <= m; ++k)
    {
        cin>>n;
        if(n < 10 || n > 10000)
        {
            cout<<"false"<<endl;
        }            
        else
        {
            s=n;
            while(s>0)
            {
                a[i]=s%10;
                s=s/10;
                i++;
            }
            up=0;
            down=0;
            for(j=0;j<i-1;j++)
            {
                if(a[j]>a[j+1])
                    up=1;
                if(a[j]<a[j+1])
                    down=1;
            }
            if(up == 1 && down == 1)
            {
                cout<<"true"<<endl;
            }
            if(up == 1 && down == 0)
            {
                cout<<"false"<<endl;
            }
            if(up == 0 && down == 1)
            {
                cout<<"false"<<endl;
            }
            if(up == 0 && down == 0)
            {
                cout<<"false"<<endl;
            }
        }
    }
    
    return 0;
}*/

/*
#include<iostream>
#include<string>
using namespace std;
string a;
 
void subseq(int i,string s)
{
    int n=a.size();
    if(i==n)
    {if(!s.empty())
    cout<<s<<endl;return;}
    subseq(i+1,s);
    s.push_back(a[i]);
    subseq(i+1,s);
}
 
int main()
{
    int i,j,k;
    getline(cin,a);
    int n=a.size();
    string s;
    subseq(0,s);
 
}*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !ArePair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(AreParanthesesBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}
