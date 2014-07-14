#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
	
};

typedef struct node  *NODE; 

NODE insert(int item, NODE head){
	
	NODE temp = (NODE) malloc(sizeof(struct node));
	temp->info=item;
	temp->link=NULL;
		
	if(head == NULL){ 
	printf("\n head inserted: %d \n",temp->info);	
	return temp;
	}
	
	NODE cur;
	NODE prev=NULL;
	cur=head;
	
	while(cur!=NULL){
		prev=cur;
		cur = cur->link;	
	}
	prev->link=temp;	
		
	printf("\n %d is inserted after %d \n",temp->info,prev->info);
	return head;
}

NODE delete(int item,NODE head){

	if(head==NULL){
		printf("\nNothing to delete\n");
		return NULL;
	}

	
	
	NODE cur,prev;
	
	cur=head;
	prev=NULL;

	while(cur!=NULL){
	
		
		
		if(cur->info==item){
			printf("\nDeleting item %d \n",item);	
			if(prev==NULL){
				head=cur->link;
				free(cur);
				return head;	
			}
			else{			
				prev->link=cur->link;
				free(cur);
				return head;
			}
		}	
		else{
			prev=cur;
			cur=cur->link;
		}
	}
	if(cur==NULL){
		printf("\nItem  %d not found...Cannot delete\n",item);	
	}
	
	return head;
		
	
	
}

NODE ntolast(NODE head, int n){
	printf("bla1");
	int i;
	
	if(head == NULL){
		printf("bla1");
		return NULL;
	}
	
	NODE prev=head , cur = head;
	
	for(i=0;i<n;i++){
		if(cur==NULL){
			printf("Position invalid");
			return NULL;		
		}
		cur=cur->link;	
	}
	
	while(cur!=NULL){
		prev=prev->link;
		cur=cur->link;	
	printf("bla3");
	}
	
	return prev; 		

	
}

void printList(NODE head){

	if(head==NULL){
		printf("\nNothing in the list\n");
		return;	
	}

	NODE cur =head;
	while(cur!=NULL){
		printf("%d\t",cur->info);	
		cur=cur->link;
		
	}
}

void main(){
	int n = 5;
	NODE head =NULL;
	head=delete(9,head);
	head=insert(2,head);	
	head=insert(1,head);
	head=insert(3,head);
	head=insert(4,head);
	
	
	printf("\n List is \n:");
	printList(head);
	
	head=delete(9,head);
	head=delete(1,head);
	head=delete(4,head);
	head=delete(2,head);
	
	printf("\n List is \n:");
	printList(head);


	head=insert(2,head);	
	head=insert(1,head);
	head=insert(3,head);
	head=insert(4,head);
	head=insert(2,head);	
	head=insert(1,head);
	head=insert(3,head);
	head=insert(4,head);
	printf("\n List is \n:");
	printList(head);

	printf("\n");

	head = ntolast(head,n);
	printf("\n List is \n:");
	printList(head);
	printf("\n");
}
