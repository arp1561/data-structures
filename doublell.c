#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next,*prev;
};
struct node *head = NULL;
struct node *curr = NULL;

void create(int val)
{
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->val = val;
    ptr->next=NULL;
    ptr->prev=NULL;
    
    head=curr=ptr;
}
void add_front(int val)
{
    if(head==NULL)
    {
        create(val);
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->val=val;
    head->prev = ptr;
    ptr->next = head;
    ptr->prev = NULL;
    head=ptr;
}
void add_end(int val)
{
    if(head==NULL)
    {
        create(val);
        return;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    new_node->val=val;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next=NULL;
}
void add_bet(int val)
{
    int search;
    if(head==NULL)
    {
        create(val);
        return;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    printf("Enter the value after which you want to delete :");
    scanf("%d",&search);
    new_node->val = val;
    while(ptr->val!=search)
        ptr=ptr->next;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
}
void delete_front()
{
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
}
void delete_end()
{
    struct node *ptr = head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->prev->next=NULL;
    free(ptr);
}
void delete_bet()
{
    int search;
    printf("Enter the value you want to search :");
    scanf("%d",&search);
    struct node *ptr = head;
    while(ptr->val!=search)
        ptr=ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev->next;
}
void display()
{
    struct node *ptr = head;
    printf("NULL<->");
    while(ptr!=NULL)
    {   
        printf("[%d]<->",ptr->val);
        ptr=ptr->next;
    }
    printf("NULL");
}
int main()
{
    for(int i=1;i<=5;i++)
        add_end(i);
    delete_bet();
    display();
}














