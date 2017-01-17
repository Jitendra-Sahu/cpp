#include<iostream>
#include<stdlib.h>
#include<pthread.h>

using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *fun(void *ptr)
{
	pthread_mutex_lock(&mutex1);
	counter++;
	cout<<((char*)ptr);
	cout<<"\nCounter value:"<<counter<<endl;
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

int main()
{
	pthread_t thread1, thread2;
	int rc1=0;
	int rc2=0;
	char msg[] = "Mutex play";
	
	rc1 = pthread_create(&thread1, NULL, fun, (void*)msg);
	if(rc1)
	{
		cout<<"\nThread1 creation failed";
	}

	rc2 = pthread_create(&thread2, NULL, fun, (void*)msg);
	if(rc2)
	{
		cout<<"\nThread2 creation failed";
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

