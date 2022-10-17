#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void taxiary(void *arg){
	printf("taxiary arrived thread\n");
	pthread_detach(pthread_self());
}
void takeTaxi(void *arg){
        printf("takeTaxi thread\n");
        pthread_detach(pthread_self());
	pthread_exit(0);
}
int main(){
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,taxiary,NULL);
	pthread_create(&tid2,NULL,takeTaxi,NULL);
	return 0;
}
