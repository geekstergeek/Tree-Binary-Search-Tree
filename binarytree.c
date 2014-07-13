#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *llink;
	struct node *rlink;

};

typedef struct node  *NODE; 
int count=0,counter=0;

void inorder(NODE root){

	if(root== NULL) return;

	inorder(root->llink);
	printf("%d",root->info);
	inorder(root->rlink);	
}

void preorder(NODE root){

	if(root== NULL) return;

	printf("%d",root->info);
	preorder(root->llink);
	preorder(root->rlink);	
}

void postorder(NODE root){

	if(root== NULL) return;

	postorder(root->llink);
	postorder(root->rlink);	
	printf("%d",root->info);
}


NODE insert(int item, NODE root){

	NODE cur,prev,temp;
	temp= (NODE) malloc (sizeof(struct node));
	
	prev=NULL;
	cur = root;
	
	temp->info = item;
	temp	->llink=temp->rlink=NULL;
	if(cur==NULL){
		
		printf("\nroot inserted with item %d  \n", item);
		return temp;	
		
	}
	while(cur!=NULL) {
		prev=cur;	
		if(item==cur->info){
			printf("\ndup items not allowed! Ignoring insertion of %d and Continuing ....\n", item);
			return root;
		}
			
		else if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;	
	} 

	if(item<prev->info)
		prev->llink = temp;
	else
		prev->rlink = temp;
	printf("\n item inserted %d  below item %d \n",item,prev->info);

	return root;
}



NODE search(int item, NODE root){

	if(root==NULL||root->info==item) return root;
	if(item<root->info) return search(item,root->llink);
	return search(item,root->rlink);
}


NODE copy(NODE root){
	
	if(root == NULL) return NULL;

	NODE temp =  (NODE) malloc(sizeof(struct node));
	
	temp->info = root->info;
	temp->llink= copy(root->llink);
	temp->rlink=copy(root->rlink);
	
	return temp;
	
	
}

void maxElement(NODE root){
	
	NODE prev;
	if(root==NULL){
		printf("root is null");
		return;	
	}
	while(root!=NULL){
		prev = root;
		root=root->rlink;	
	}
	printf("\nMax element: %d", prev->info);

	return;
}

void minElement(NODE root){
	
	NODE prev;
	if(root==NULL){
		printf("root is null");
		return;	
	}
	while(root!=NULL){
		prev = root;
		root=root->llink;	
	}
	printf("\nMax element: %d", prev->info);

	return;
}

int maximum(int a, int b){
	
	return (a>b) ? a:b ;
}

int height(NODE root){
	if(root==NULL) return 0;
	
	return 1+maximum(height(root->llink),height(root->rlink));
}

int countLeaves(NODE root){
	
	if(root==NULL) return;
	countLeaves(root->llink);
	if(root->llink==NULL&&root->rlink==NULL) count++;
	countLeaves(root->rlink);
	return count;
}

int countNodes(NODE root){
	
	if(root==NULL) return;
	

	countNodes(root->llink);
	counter++;
	countNodes(root->rlink);

	return counter;
}

int main(){

	
	NODE root =NULL;
	int a=0;

	if(search(19,root)){
	printf("found\n");
	}
	else{
	printf("not found\n");
	}

	root = insert(5,root);
	root = insert(2,root);
	root = insert(1,root);
	root = insert(3,root);
	root = insert(1,root);
	
	root = insert(4,root);
	root = insert(6,root);
	root = insert(7,root);
	root = insert(8,root);
	root = insert(9,root);

	printf("\ninorder:\t");
	inorder(root);
	
	printf("\npreorder:\t");
	preorder(root);

	printf("\npostorder:\t");
	postorder(root);
	
	printf("\n");
	if(search(19,root)){
	printf("found\n");
	}
	else{
	printf("not found\n");
	}
	
	printf("\nNew Tree Copy ... \n");
	root = copy(root);
	inorder(root);

	maxElement(root);
	printf("\n");
	minElement(root);
	printf("\n");	
	
	printf("Height of Tree %d",height(root));	
	printf("\n");

	printf("Number of Leaves = %d", countLeaves(root));
	printf("\n");

	printf("Number of Nodes %d", countNodes(root));
	
	printf("\n");
}
