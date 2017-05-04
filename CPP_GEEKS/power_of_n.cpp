//Check if number is a power of 2

#include<iostream>
#define NUM_BITS_INT (8*sizeof(int))

using namespace std;

bool check_pow_n(int num)
{
	/*int i, count = 0, res, shift_num;

	for(i=0; i <= NUM_BITS_INT; ++i)
	{
		shift_num = num >> i;
		res = shift_num & 1;
		if(res == 1)
			++count;
	}
	if(count % 2 == 1)
		return true;
	else
		return false;
	*/
	if (num == 0)
    		return 0;
  	while (num != 1)
  	{
    		if (num%2 != 0)
      			return 0;
    		num = num/2;
  	}
	return true;
}

int main()
{
	int in_num;
	cout<<"\nEnter a number";
	cin>>in_num;

	bool res = check_pow_n(in_num);

	//if((in_num != 1) && (in_num & (in_num - 1)))
	if(res)
	{
		cout<<in_num<<" is power of 2\n";
	}
	else
	{
		cout<<"\nNot a power of 2\n";
	}

	return 0;
}
