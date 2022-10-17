#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
	perror("fork");
	return 0;
	}
	else if(pid>0){
	exit(0);
	}
	printf("i am a deam\n");
	printf("sid = %d,pid = %d,pgid = %d\n",getsid(getpid()),getpid(),getpgid(getpid()));
	if(setsid()<0){
	perror("setsid");
	exit(0);
	}
	printf("after sid = %d,pid = %d,pgid = %d\n",getsid(getpid()),getpid(),getpgid(getpid()));


	close(0);
	close(1);
	close(2);
	sleep(100);

	return 0;
}
