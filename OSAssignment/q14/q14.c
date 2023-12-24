/* 14. Write a program to read and write contents in a file using fopen, fread, fwrite and fclose library calls */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp;
	char name[10];
	int rollno, val , ret;
	fp = fopen("Studentrecord.txt","w");
	if(fp==NULL)
	{
		perror("msg:");
		exit(1);
	}
	
	printf("Enter Name: ");
	scanf("%s",name);
	val = fwrite(name,strlen(name),1,fp);
	printf("%d\n",val);
	if(val != 1) {
		perror("MSG");
		exit(1);
	}
		
	printf("Enter Rollno: ");
      	scanf("%d",&rollno);
	ret = fwrite(&rollno,sizeof(int),1,fp);
	if(ret != 1) {
		perror("MSG");
		exit(1);
	}

	fclose(fp);

	fp = fopen("Studentrecord.txt","r");
	if(fp==NULL)
	{
		perror("msg:");
		exit(1);
	}

	val = fread(name, strlen(name), 1, fp);
	if(val != 1) {
		perror("MSG");
		exit(1);
	}

	printf("%s\n",name);
        ret = fread(&rollno, sizeof(int), 1, fp);
	if(ret != 1) {
		perror("MSG");
		exit(1);
	}
	printf("%d\n",rollno);

	return 0;
}


	
