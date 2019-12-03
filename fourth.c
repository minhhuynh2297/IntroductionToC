#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
	int value;
	int key; 
	struct node* next;
};

struct node* first=NULL;
struct node* temp; 
struct node* hash[1000]; //hash table of nodes 1000 across


int search(int key, int s){
	temp=(struct node*)malloc(sizeof(struct node)); 
	temp=hash[key];
	//printf("%d", temp->value); 
	while(temp!=NULL && temp->value!=s){ //first node in the key is done
	//	printf("%d", temp->value); 
		temp=temp->next;
	}
	if(temp==NULL){
	//	printf("search is fine1\n");
		return 0; 
	}
	if(temp->value==s){
	//	printf("search is fine2\n");
		return 1; 
	}
	else{
		return 0;
	}
}

int insert(int key, int i){
	int s=search(key, i);
	if(s==1){ //duplicate found
	//	printf("inserting %d\n", first->value); 
		return 1;
	}
	if(s==0){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->value=i;
		temp->key=key;
		temp->next=first;
		first=temp;
//		printf("inserting %d\n", first->value); 
		hash[key]=first; 
		return 0;
	}
	else{
		return 0;
	}
}


int main(int argc, char** argv){

	char type;

	int value, key, a, b;

	char tab; 

	FILE* file; 

	if(argc!=2){
		exit(0);
	}

	file=fopen(argv[1], "r"); //opens the file name found in argv[1], in read mode	

	if(file!=NULL){ //if a file is inputed, the program continues

			while(fscanf(file, "%c%c%d\n", &type, &tab, &value)!=EOF){
				if((type=='i') && (value/1 == value) && (tab=='\t')){ 
					key=abs(value%1000);
					b=insert(key, value); 
					if(b==0){
						printf("inserted\n");
					}
					if(b==1){
						printf("duplicate\n"); 
					}
				}
				else if((type=='s') && (value/1 == value) && (tab=='\t')){
					a=search(key, value); 
					if(a==0){
						printf("absent\n");
					}
					if(a==1){
						printf("present\n");
					}
				}
				else if(type!='i' && type!='s'){
					printf("error\n");
				}
				else{
					printf("error\n");
				}

		}
	}

	else{ //ends the program by printing error if a file is not included. 
		printf("error\n");
	}
return 0;
}
