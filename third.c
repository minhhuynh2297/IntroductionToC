#include <stdio.h>
#include <stdlib.h>

struct nodes{ //every node we make will have these variables

	int value; //the value
	struct nodes* next; //a next node
	struct nodes* prev; //a previous node
};


struct nodes* first=NULL;
struct nodes* current;
struct nodes* temp; 

int count=0; 

void print(){
	temp = first;
	while(temp != NULL){
		printf("%d\t", temp->value);
		temp=temp->next;
	}
}

void insert(int i){
	
	temp=(struct nodes*) malloc(sizeof(struct nodes));

	if(count==0){ //first node
		temp->value=i; //temp's value is now the valuue
		//temp->next=first assign temp's next to the first node;
		first=temp; //make temp first as well
		first->next=NULL; 
		first->prev=NULL;
		count=count+1; 
		return; 
	}

	else{
		if(i > first->value){ //i is greater than first

			current=first; 
			while(current->next!=NULL && current->value < i){ 
				current=current->next; 
			}

			if(current->next==NULL){ //put it at the last (it is the largest in the LL)
				temp->value=i;
				temp->prev=current;
				current->next=temp; 
				temp->next=NULL; 
				count=count+1;
				return; 
				
			}
			
			if(current->value == i){ //does nothing if it is the same value
				return;
			}
			
			if(current->value > i){ 
				temp->value=i;
				current->prev->next=temp;
				temp->next=current; 
				count=count+1;
				return; 
			} 
			
		}
		
		if(i < first->value){ //i is less than the first (smallest number)
			temp->value=i;
			first->prev=temp;
			temp->next=first;
			temp->prev=NULL;
			first=temp; 
			count=count+1;
		
		}
		
		if(i == first->value){ //same value as first
			return; 
		}


	}

}

void delete(int d){
	if(count==0){
		return;
	}
	if(first->value==d){ //it's the first one
		if(count==1){
			first=NULL; 
			count=count-1; 
			return;
		}

		else{
			first=first->next;
			count=count-1;
			return;
		}
	}
	
	current=first;
	while(current->value!=d && current->next!=NULL){ //find what to delete
		current=current->next;
	}
		
	if(current->value==d){ //we found it
		current->prev->next=current->next; // deletes the middle by connecting previous and next; 
		count=count-1; 
		return;
	}
	if(current->next==NULL){ //what we want isn't there
		return;
	}

}
	
int main(int argc, char** argv){

	char type;

	char tab;

	int value;

	FILE* file; 

	if(argc!=2){
		exit(0);
	}

	file=fopen(argv[1], "r"); //opens the file name found in argv[1], in read mode	

	if(file!=NULL){ //if a file is inputed, the program continues

		while(fscanf(file, "%c%c%d\n", &type, &tab, &value)!=EOF){

			if((type=='d') && (value/1 == value) && (tab=='\t')) {
				delete(value); 
			}

			else if((type=='i') && (value/1 == value) && (tab=='\t')){
				insert(value); 
			}
 
			else{
				printf("error\n");
				exit(0); 
			}
		}
	}

	else{ //ends the program by printing error if a file is not included. 
		printf("error\n");
		exit(0);
	}
	print();
	printf("\n");
return 0;
}

