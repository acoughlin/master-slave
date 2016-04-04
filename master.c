
/* exec example                             *
* for CS-350                             *        
* to run master                            *
*  type on command line,                   *
*   master 4 5                             *
*  master takes two command line arguments.*
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i,result=0, status;
	pid_t pid1 = -1;
	pid_t pid2 = -1; 
	pid_t pid3 = -1;
	pid_t pid4 = -1;
	int first = 1, second = 2;

	// get the path of the current working directory for slave
	// to get path, on command line type, pwd

	char  *procpath = "/home/alex/Desktop/windowsbackup/SCHOOL+CODE/COMP350/proj1/slave";
	char  *procname = "slave";

	// or get it as  char pathname[100];
	/* get process path 

	if(getwd(pathname) == NULL)
	{
	printf("Error retrieving path\n");
	return 0;
	}

	*/	

	//create a child process
	pid1 = fork();
	int zz = 1;
	if (pid1 == 0)
	{	

		for(; zz <= argc+1; zz=zz+2){
			if(zz==1){}
			if (zz>3 && pid2 == -1){ 
				printf("print2 CREATED\n");
				pid2=fork();
			}
			else if (zz>5 && pid2==0 && pid3 == -1){ 
				printf("print3 CREATED\n");
				pid3=fork();
			}	
			else if (zz>7 && pid3==0){ 
				printf("print4 CREATED\n");
				pid4=fork();
			}
			
		}/*
		if (pid3 > 0 && pid2 > 0){
			waitpid(pid3, &status, 0);
			printf("pid3 status is %d\n", status);
			result = status /256;
			printf("result is %d\n", result);
			second=6;
			if(argc==6){
				printf("ppppp\n");
				argv[second]="0";
			}
			first=5;
			sprintf(argv[first], "%d", result+atoi(argv[first]));	

		}

		if(pid2 > 0){
			waitpid(pid2, &status, 0);
			printf("pid2 status is %d\n", status);
			result = status /256;
			printf("result is %d\n", result);
			second=4;
			if(argc==4){
				argv[second]="0";
			}
			printf("argv[second] is %s\n", argv[second]);
			first=3;
			sprintf(argv[first], "%d", result+atoi(argv[first]));
		}

//		printf("EXECUTING \n");
//		printf("status is %d\n", status);
//		printf("result is %d\n", result);
//		printf("argv[second] is :%d\n", atoi(argv[second]));
	*/
		if(pid4==0){
			first=1;
			second=2;
		}
		else if(pid3==0) {
			if(argc==6){argc++;
			}
			waitpid(pid4, &status, 0);
			int argcminus5 = argc-5; 
			int argcminus6 = argc-6;
			printf("status pid3: %d\n", status);
			printf("pid1 pid2 pid3 pid4: %d, %d, %d, %d\n", pid1, pid2, pid3, pid4);
			result = result + status /256; 
			first=argc-6;
			second=argc-5;
			if(argc>7) sprintf(argv[first], "%d", result+atoi(argv[first]));
		}
		else if(pid2==0){
			waitpid(pid3, &status, 0);
			int argcminus3 = argc-3; 
			int argcminus4 = argc-4;
			printf("status pid2: %d\n", status);
			printf("pid1 pid2 pid3 pid4: %d, %d, %d, %d\n", pid1, pid2, pid3, pid4);
			result = status /256; 
			printf("pid2 result: %d\n", result);
			first=1;
			if(argc==6)
				first=2;
			second=argcminus3;
			sprintf(argv[first], "%d", result+atoi(argv[argcminus4]));
			if(argc==6)sprintf(argv[first], "%d", result+atoi(argv[argc-6]));
		}
		else if(pid1==0) {
			waitpid(pid2, &status, 0);
			printf("status pid1: %d\n", status);
			printf("pid1 pid2 pid3 pid4: %d, %d, %d, %d\n", pid1, pid2, pid3, pid4);
			result = status /256;
			int argcminus1 = argc-1;
			int argcminus2 = argc-2; 
			first=1; second=argcminus1;
			if(argc==3)
				second=2;
			if(argc>3) sprintf(argv[1], "%d", result+atoi(argv[argcminus2]));
			if(argc==2) {second=0; sprintf(argv[second], "%d", 0); }
		}	
		printf("FIRST AND SECOND ARGS: %s, %s\n", argv[first], argv[second]);
		execl(procpath, procname, argv[first], argv[second], (char *) 0);


		// if exec returns, means the call has failed.
		perror("execl failed to run slave program");
		exit(1);
	}	
	//      int finalSum=0;
	//child process execution code--shows exec family calls
	//      execl(procpath, procname, argv[3], argv[4], (char *) 0);

	// execvp(procname,argv);

	else if (pid1 > 0)
	{

		// print out command line arguments
		printf("I'm the master and printing out my command line arguments\n");
		//print arguments
		int p = 1;
		printf("ARGC=%d\n", argc);
		for(; p < argc; p++){
			printf("MASTER: arguement #%d = %s\n", p, argv[p]);
		}
//		printf("%d", pid1);
//		printf("\n");
		//wait for slave's exit value
		waitpid(pid1, &status, 0); 
		// shift the status by 8 bits to get the sum in result
//		printf("result before second status computation is: %d\n", result);
		result = result + status /256; 
//		printf("final status is %d\n", status);
//		printf("final result is %d\n", result);
		printf("SUM IS: %d\n",result); //print sum
		exit(0);
	}

	else
	{
		printf("call to fork failed, no child\n");
		exit(-1);
	}
}
