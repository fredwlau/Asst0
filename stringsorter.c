#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//struct object for nodes in linkedlist to store words
typedef struct node{
	char *string;
	struct node *next;
	}node_t;

//global declaration for our head of linkedlist
node_t *head=NULL;
//function to create new node and insert it into list
void makeInsert(char *word){
	node_t *newNode=malloc(sizeof(node_t));
	newNode->string=word;
	newNode->next=NULL;
	//check to see if we have an empty list, if we do, simply assign the new node as the head node
	if(head==NULL){
		head=newNode;
		}
	else{
	//not an empty list, need two nodes to traverse so we can find the correct place to insert new node
		node_t *curr=head;
		node_t *prev=NULL;
		while(curr!=NULL){
			if(strcmp(curr->string, newNode->string)>=0){
				break;
				}
			else{
				prev=curr;
				curr=curr->next;
				}
			}
		if(curr==head){
			newNode->next=head;
			head=newNode;
			}
		else{
			newNode->next=curr;
			prev->next=newNode;
			}
		}
	}


//read in two arguments, first arg is run command and second arg is string to be analyzed
int main(int argc, char** argv){
	if (argc ==1 || argc >2){
		printf("Error: bad input\n");
		return 0;
		}
	//iterate through the string to be analyze
	int i;
	for (i=0; i<strlen(argv[1]); i++){
		//check non-alpha first in case the input string starts with bullshit
		if(!isalpha(argv[1][i])){
			continue;
			}
		//we have read an alphabetical character so we know we have to store whatever comes after this
		else {
			//since we don't know how large the word is we can start with the minimum size and increase later
			char *s=malloc(1);
			int j=0;
			//iterate until we reach non-alpha character
			while(isalpha(argv[1][i])){
				
				//store each alphabetical character into our string
				s[j]=argv[1][i];
				//increase size of string as needed
				s=realloc(s, j+1);
				//increment i to next character in string
				j++;
				i++;
				}
			makeInsert(s);
			}
		}
	
	node_t *temp=head;
	//print out the sorted linked list with our words
	while(temp!=NULL){
		printf("%s\n", temp->string);
		temp=temp->next;
		}
	return 0;
	}	
