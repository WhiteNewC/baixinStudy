#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *testThread(void* arg){
	printf("thread test\n");
	printf("test tid = %lu\n",pthread_self());
	printf("arg = %d\n",arg);
	pthread_exit(NULL);
	printf("after pthread\n");
	return NULL;
}
int main(){
	pthread_t tid;
	int ret;
	int arg = 5;
	ret = pthread_create(&tid,NULL,testThread,arg);
	printf("main test\n");
	printf("tid =%lu \n",tid);
	sleep(1);
	return 0;
}
