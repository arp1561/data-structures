#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *curr = NULL;

void create_list(int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->val = val;
    ptr->next=NULL;

    head=curr=ptr;

}
void add_to_list(int val,bool ate)
{
    if(head==NULL)
    {
        create_list(val);
        return;
    }
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->val=val;
    if(ate)
    {
        curr->next = ptr;
        curr=ptr;
    }
    else
    {
        ptr->next = head;
        head=ptr;
    }
}
void add_in_bet(int val)
{
    int search;
    printf("Enter the value after which you want to add :");
    scanf("%d",&search);
    struct node *ptr = head;
    struct node *preptr=ptr;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    while(preptr->val!=search)
    {
        preptr=ptr;
        ptr=ptr->next;

    }
    preptr->next = new_node;
    new_node->next = ptr;
}
void delete_from_front()
{
	struct node *ptr=head;
	head = head->next;
	free(ptr);
}
void delete_from_end()
{
	struct node *ptr=head;
	struct node *preptr=ptr;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
}
void delete_mid()
{
	int val;
	printf("Enter the value you want to delete :");
	scanf("%d",&val);
	struct node *ptr=head;
	struct node *preptr=ptr;
	while(ptr->val!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	
	}
	preptr->next=ptr->next;
	free(ptr);
}

void display()
{
    struct node *ptr = head;
    while(ptr!=NULL)
    {   
        printf("[%d]->",ptr->val);
        ptr=ptr->next;
    }
    printf("NULL");
}
void main()
{
    for(int i=1;i<=5;i++)
        add_to_list(i,true);
	delete_mid();
	display();


}


