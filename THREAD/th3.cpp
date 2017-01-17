#include<iostream>
#include<pthread.h>
#include<stdlib.h>

using namespace std;

void* print(void *ptr)
{
	pthread_t *self_tid = NULL;
	self_tid = (pthread_t*)malloc(sizeof(pthread_t));
	*self_tid = pthread_self();
	cout<<"\nThread id invoked:"<<*self_tid;
	cout<<"\nMsg is:"<<((char*)ptr);
	pthread_exit((void*)self_tid);
}

int main()
{
	pthread_t thread_id;
	pthread_t *tid;
	int status = 0;
	char arg1[] = "This is sample program to fetch return value from a thread";

	status = pthread_create(&thread_id, NULL, print, (void*)arg1);
	if(status)
	{
		cout<<"\nThread creation failed";
	}
	else
	{
		cout<<"\nThread id created: "<<thread_id;
	}

	pthread_join(thread_id, (void**)&tid);
	cout<<"\ntid received: "<<(*tid);

	return 0;
}	
