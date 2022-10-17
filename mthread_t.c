#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *testThread(void* arg){
	printf("this is %d thread\n",*(int *)arg);
	pthread_exit(NULL);
	printf("after pthread\n");
	return NULL;
}
int main(){
	pthread_t tid[5];
	int ret;
	int arg = 5,i;
	for(i = 0;i<5;i++){
	    ret = pthread_create(&tid[i],NULL,testThread,(void *)&i);
	    printf("tid =%lu \n",tid[i]);
	    sleep(1);

	}
	printf("main test\n");
	sleep(1);
	return 0;
}
