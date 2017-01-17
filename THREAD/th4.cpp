#include<iostream>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void* print(void* ptr)
{
	int *arg;
	cout<<"\nThread started";
	
	arg = (int*)ptr;
	sleep(*arg);
	free(arg);
	cout<<"\nThread exiting\n";
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	int status = 0;
	int *arg = NULL;
	
	arg = (int*)malloc(sizeof(int));
	if(arg == NULL)
	{
		cout<<"\nMalloc failed. exiting.";
		return -1;
	}
	*arg = 10;
	
	status = pthread_create(&tid, NULL, print, (void*)arg);
	if(status)
	{
		cout<<"\nThread creation failed";
	}
	else
	{
		cout<<"\nThread id created:"<<tid;
	}
	
	status = pthread_detach(tid);
	if(status == 0)
		cout<<"\nConverted thread detachable";

	pthread_exit(NULL);
	return 0;
}
