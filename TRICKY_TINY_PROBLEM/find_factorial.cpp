//To Find Factorial Of A Number Using C Program

#include<iostream>

using namespace std;

/* Using Recursion

int factorial(int data)
{
	if(data == 1)
		return 1;
	else
		return (data * factorial(data-1));
}

int main()
{
	int in_num;

	cout<<"Enter number for factorial: ";
	cin>>in_num;

	long int result = factorial(in_num);

	cout<<"\n Result: "<<result;
	cout<<endl;

	return 0;
}

*/

/* Using for loop */

int main()
{
        int in_num;

        cout<<"Enter number for factorial: ";
        cin>>in_num;

        long int result = 1;
	for(int i = 1; i <= in_num; ++i)
		result = result * i;

        cout<<"\n Result: "<<result;
        cout<<endl;

        return 0;
}


