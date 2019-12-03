#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	if(argc!=2){
		printf("error\n");
		exit(0);
	}

	int value=atoi(argv[1]);

	int divisor;

	int counter=0;


	for(divisor=2; divisor<value; divisor=divisor+1){

		if(value%divisor==0){
			printf("no\n");	
			counter++; 
			break;
		}

	}

	if(counter==0){
		printf("yes\n");
	}

return 0; 
}
