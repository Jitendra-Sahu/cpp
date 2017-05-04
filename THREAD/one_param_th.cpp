#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct record
{
	int count;
	char array[15];
};

void *example_thread(void *r)
{
	struct record *r1 = (struct record*)r;
	printf("\nargument are %d and string as %s\n", r1->count, r1->array);
}

int main()
{
	pthread_t thr1;
	
	int ret;
	int count = 12;
	struct record r1 = {4, "hello"};

	ret = pthread_create(&thr1, NULL, example_thread, (void*)&r1);

	if(ret != 0)
	{
		printf("\nerror in thread creation");
	}

	pthread_join(thr1, NULL);
	
	return 0;
}
