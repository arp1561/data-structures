#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *left;
	struct node *right;	
};

struct node *root;
struct node *insert (struct node *r, int data);
void inorder(struct node *r);
void preorder(struct node *r);
void postorder(struct node *r);

int main(){
	root = NULL;
	int i, n,v;
	printf("How many values do you want to insert?\n");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("Data %d",i+1);
		scanf("%d",&v);
		root = insert(root,v);
	}
	printf("Inorder traversal : ");
	inorder(root);
	printf("\n");
	printf("Postorder Traversal : ");
	postorder(root);
	printf("\n");
}

struct node *insert(struct node *r, int data){
	if(r==NULL){
		r = (struct node *)malloc(sizeof(struct node));
		r-> value = data;
		r-> left = NULL;
		r-> right = NULL;
	}
	else if(data < r->value){
		r->left = insert(r->left,data);
	}
	else{
		r->right = insert(r->right,data);
	}
	return r;
}

void inorder(struct node *r){
	if(r!=NULL){
		inorder(r->left);
		printf("%d\t",r->value);
		inorder(r->right);
	}
}

void preorder(struct node *r){
	if(r!=NULL){
		printf("%d\t",r->value);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(struct node *r){
	if(r!=NULL){
		postorder(r->left);
		postorder(r->right);
		printf("%d\t",r->value);
	}
}
