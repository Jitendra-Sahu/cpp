#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

void *functionCounter1(void *ptr);
void *functionCounter2(void *ptr);
int count = 0;

#define COUNT_DONE 20

int main()
{
	pthread_t thr1, thr2;
   	char msg[] = "odd & even with conditional variable & mutex";
	
	pthread_create(&thr1, NULL, functionCounter1, (void*)msg);
	pthread_create(&thr2, NULL, functionCounter2, (void*)msg);

	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);

	exit(0);
}

void *functionCounter1(void *ptr)
{
   	printf("fun1 message: %s \n", (char*)ptr);
	for(;;)
	{
		pthread_mutex_lock(&count_mutex);
		
		if(count % 2 == 0)
		{
			pthread_cond_wait(&cond_var, &count_mutex);
		}
		
		++count;
		printf("\ncount value in funct2:%d ",count);
		pthread_cond_signal(&cond_var);

		if(count >= COUNT_DONE)
		{
			pthread_mutex_unlock(&count_mutex);
			return NULL;
		}

		pthread_mutex_unlock(&count_mutex);
	}
}

void *functionCounter2(void *ptr)
{
   	printf("fun1 message: %s \n", (char*)ptr);
	for(;;)
        {
                pthread_mutex_lock(&count_mutex);

                if(count % 2 != 0)
                {
                        pthread_cond_wait(&cond_var, &count_mutex);
                }

                ++count;
		printf("\ncount value in funct1:%d ",count);
                pthread_cond_signal(&cond_var);

                if(count >= COUNT_DONE)
                {
                        pthread_mutex_unlock(&count_mutex);
                        return NULL;
                }

                pthread_mutex_unlock(&count_mutex);
	}
}


