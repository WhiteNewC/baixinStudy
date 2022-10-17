#include<stdio.h>

#include<unistd.h>

int main(){

    if(execlp("ls","ls","-a","-l","/etc",NULL)<0){
	    perror("execl");
    }

    return 0;
}
