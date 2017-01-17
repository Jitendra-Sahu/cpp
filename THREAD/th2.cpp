#include<iostream>
#include<pthread.h>

using namespace std;

void *print(void *ptr)
{
	cout<<"\nThread id="<<pthread_self()<<" invoked msg:"<<(char*)ptr<<endl;
	return NULL;
}

int main()
{
	pthread_t thread1_id, thread2_id;
	int status = 0;
	char arg1[] = "This is sample program to create joinable threads";
	char arg2[] = "Demonstrating use of pthread_create(), pthread_self(), pthread_join() ";

	status = pthread_create(&thread1_id, NULL, print, (void*)arg1);
	if(status)
		cout<<"\nThread1 creation fail";
	else
		cout<<"\nThread1 id:"<<thread1_id;/*<<"\tcreated";*/

	status = pthread_create(&thread2_id, NULL, print, (void*)arg2);
	if(status)
		cout<<"\nThread2 creation fail";
	else
		cout<<"\nThread2 id:"<<thread2_id;/*<<"\tcreated";*/

	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);

	return 0;
}
