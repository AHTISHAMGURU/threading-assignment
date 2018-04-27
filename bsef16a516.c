#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * sum(void* a);

int array[1000];

int main()
{
pthread_t aThread[10];
int  sum[10] , tsum , index=0;

for(int i=0 ; i<1000 ; i++)
{
	array[i]=i;
}

for(int i=0 ; i<1000 ; i=i+100)
{
pthread_create(&aThread[index], NULL, sum, (void*)i);
index++;
}

index=0;

for(int i=0 ; i<10 ; i++)
{
pthread_join(aThread,(int*)sum[index]);
	tsum = tsum + sum[index];
}

printf("sum is: %d",tsum);
return 0;
 }


void * sum(void *a)
{
int* arg=(int*)a;
int sum=0;
for(int x=arg ; x<arg+100 ; x++)
{
	sum = sum + array[x];
}
    return (void*) sum;
}
