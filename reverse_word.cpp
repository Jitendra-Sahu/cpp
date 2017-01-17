#include<iostream>
#include<stack>

using namespace std;

void reverse(char* begin, char* end)
{
        char temp;
        while(begin < end)
        {
                temp = *begin;
                *begin++ = *end;
                *end-- = temp;
        }
}

void reverseWords(char* s)
{
        char *word_begin = s;
        char *temp = s;

        while(*temp)
        {
                temp++;
                if(*temp == '\0')
                {
                        reverse(word_begin, temp-1);
                }
                else if(*temp == ' ')
		{
			reverse(word_begin, temp-1);
			word_begin = temp+1;
		}
	}
	reverse(s, temp-1);
}

//Using Stack
void reverse(char* p)
{
	stack<char>s;
	for(int i=0; i < strlen(p); ++i)
	{
		s.push(p[i]);
	}
	for(int i=0; i < strlen(p); ++i)
	{
		p[i] = s.top();
		s.pop();
	}
}
int main()
{
	char s[]="i like this program very much";
	char *temp =s;
	reverseWords(s);
//	reverse(s);
	cout<<s<<endl;
	return 0;
}
