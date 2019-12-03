#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) { //argc = counter , char** is a two dimensional array 	

	if(argc!=2){
		printf("error\n");
		exit(0);
	}

	int input=atoi(argv[1]);

	if (input%2 == 0){
		printf("even\n");
		exit(0);
	}

	else {
		printf("odd\n");
		exit(0);
	}

	return 0; 	
}
