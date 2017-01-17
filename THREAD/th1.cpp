#include<pthread.h>
#include <unistd.h>
#include<iostream>

using namespace std;

void *hello(void *tid)
{
//	long t;
//	t = (long) tid;
	for(int i = 20; i > 10; --i)
	{
		cout<<i<<"\n";
	}
	cout<<"\n Hello world, ";
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pid_t pid;
	pthread_t tid;
	long t;
	pid = getpid();
	cout<<"\n pid = "<<pid<<endl;

	/*for(int i=0; i < argc; i++)
	{
		cout<<"\n argv["<<i<<"]"<<":"<<argv[i]<<"\n";
	}*/

	int rc = pthread_create(&tid, NULL, hello, (void *)t);

	cout<<"\n In main cout"<<"\n";
	for(int i = 0; i < 10; ++i)
        {
                cout<<i<<" ";
        }

	//cout<<"thread value: "<<pthread_self();
	//pthread_join(tid, NULL);

	pthread_exit(NULL);

	return 0;
}
