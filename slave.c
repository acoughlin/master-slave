

/* exec example-- slave *

 * for CS-350               */



 #include <stdio.h>

 #include <stdlib.h>

 #include <sys/types.h>

 

 

int  main(int argc, char *argv[])

{

    int sum;

    printf("I'm the slave and printing out the command line arguments of my master\n");

    printf("SLAVE: first argumement = %s, second argument = %s\n", argv[1], argv[2]);

    sum = atoi(argv[1]) + atoi(argv[2]);   

    exit(sum);

 }
