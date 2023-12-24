/* 17. Write a program to demonstrate the usage of fork API to create new processes on Embedded Linux. */

#include<stdio.h>
#include<unistd.h>

int main() {
	int ret_value;
	printf("Process id %d\n", getpid());
	
	ret_value = fork();

	if(ret_value < 0) {
		printf("\nFork Failure\n");
	}
	else if(ret_value == 0) {
		printf("\nChild Process\n");
		printf("Child Process id %d\n", getpid());
		int i=5;
		while(i) {
			printf("Child is Sleeping %d\n",i);
			sleep(1);
			i--;
		}
	}
	else {
		//wait();
		printf("\nParent Process\n");
		printf("Parent Process id %d\n", getpid());
		printf("Parent is waiting\n");
		wait();
		printf("Child and process executed successfully\n");
	}
	return 0;
}

