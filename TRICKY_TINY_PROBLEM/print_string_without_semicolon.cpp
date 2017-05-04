//C program to print hello world without using semicolon

#include<iostream>

int main()
{
	/*if(std::cout<<"hello world")
	{
	}*/

/*	while(std::cout<<"hello world")
	{
	}*/

	switch(!(std::cout<<"hello world"))
	{

	}

	while(!(std::cout<<"hello world"))
        {
        }

//Correct answer to print string is using if block & will print once.
//With while it is going in infinite loop :(

}
