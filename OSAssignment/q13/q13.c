/*13. Write a program to read and write contents in a file using open, read, write and close systems calls. */
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd;
	char buff[50];
	char str[50]="Hello - World!";
	
	//fd=open("file.txt", O_CREAT, S_IWUSR);
	fd = open("file. txt", O_RDWR | O_CREAT, 0666);
	printf("fd = %d",fd);

	if(fd != -1)
	{
		printf("\nfile.txt opened with read write access\n");
		int nwrite = write(fd,str,strlen(str));
		
		if(nwrite != strlen(str)) {
			perror("MSG");
			return -1;
		}

		lseek(fd,0,SEEK_SET);

		int nread = read(fd,buff,strlen(str));
		
		if(nread != strlen(str)) {
			perror("MSG");
			return -1;
		}

		printf("\n%s if written to file.txt\n", buff);

	}

	return 0;
}
