#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct link_list
{
    int item;
    struct link_list *next;
    struct link_list *prev;
};
typedef struct link_list node;
node *start=NULL;
node* ins_first(node*);
node* ins_end(node*);
node* ins_before(node*);
node* ins_after(node*);
node* print(node*);
node* del_first(node*);
node* del_end(node*);
node* del_node(node*);

int main()
{
    int option;
    do
    {
        printf("**************MENU**************\n");
        printf("\n 1. Insert the first node ");
        printf("\n 2. Print list " );
        printf("\n 3. Insert a node at the end ");
        printf("\n 4. Insert a node before ");
        printf("\n 5. Insert a node after ");
        printf("\n 6. Delete the first node ");
        printf("\n 7. Delete the last node ");
        printf("\n 8. Delete a particular node ");
        printf("\n 9. Exit ");
        printf("\n Choose an option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: start=ins_first(start);
                    break;
            case 2: start=print(start);
                    break;
            case 3: start=ins_end(start);
                    break;
            case 4: start=ins_before(start);
                    break;
            case 5: start=ins_after(start);
                    break;
            case 6: start=del_first(start);
                    break;
            case 7: start=del_end(start);
                    break;
            case 8: start=del_node(start);
                    break;
        }
    }while(option!=9);
    getch();
    return 0;
}


node* print(node *start)
{
    node* temp;
    if(start==NULL)
    {
        printf("\n The list is empty!! ");
    }
    else if(start->next==NULL)
    {
        printf("\n The list is as follows:");
        printf("<-- %d --> ", start->item);
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
              printf("<-- %d --> ", temp->item);
              temp=temp->next;
        }
        printf("<-- %d -->", temp->item);
    }
    printf("\n");
    return start;
}

node* ins_first(node *start)
{
    int x;
    node *temp;
    printf("\n Enter the item value for the first node: ");
    scanf("%d", &x);
    temp=(node*)malloc(sizeof(node));
    temp->item=x;
    if(start==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start->prev=temp;
    }
    temp->prev=NULL;
    start=temp;
    return start;
}

node* ins_end(node *start)
{
    int x;
    node *temp, *ptr;
    temp=(node*)malloc(sizeof(node));
    printf("\n Enter the item for the node: ");
    scanf("%d", &x);
    temp->item=x;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
    temp->next=NULL;
    return start;
}

node* ins_before(node *start)
{
    int num, val;
    node *temp, *ptr, *new_node;
    printf("\n Enter the value of the node to be inserted: ");
    scanf("%d", &val);
    printf("\n Enter the value of that node's item before which insertion has to be performed: ");
    scanf("%d", &num);
    new_node=(node*)malloc(sizeof(node));
    new_node->item=val;
    temp=start;
    ptr=temp;
        while(temp->item!=num)
        {
            ptr=temp;
            temp=temp->next;
        }
       ptr->next=new_node;
       new_node->next=temp;
       new_node->prev=ptr;
       temp->prev=new_node;
       return start;

}

node* ins_after(node *start)
{
    int num, val;
    node *temp, *ptr, *new_node;
    printf("\n Enter the value of the node to be inserted: ");
    scanf("%d", &val);
    new_node=(node*)malloc(sizeof(node));
    new_node->item=val;
    printf("\n Enter the value of that node's item after which insertion has to be performed: ");
    scanf("%d", &num);
    temp=start;
    while(temp->item!=num)
    {
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=new_node;
    new_node->next=ptr;
    ptr->prev=new_node;
    new_node->prev=temp;
    return start;
}

node* del_first(node *start)
{
    if(start==NULL)
    {
        printf("\n The list is empty, UNDERFLOW!!!");
    }
    else
    {
        node *temp;
        temp=start;
        if(start->next==NULL)
        {
            start=NULL;
        }
        else
        {
            start=temp->next;
            start->prev=NULL;
        }
        printf("\n First node deleted!! ");
        free(temp);
    }
    return start;
}

node* del_end(node *start)
{
    if(start==NULL)
    {
        printf("\n The list is empty, UNDERFLOW!!! ");
    }
    else
    {
        node *temp, *ptr;;
        temp=start;
        while(temp->next!=NULL)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        free(temp);
        printf("\n The last node has been deleted!!");
    }
     return start;
}

node* del_node(node *start)
{
    int num;
    node *temp, *ptr;
    if(start==NULL)
    {
        printf("\n The list is empty, UNDERFLOW!!! ");
    }
    else
    {
        printf("\n Enter the item of the node to be deleted: ");
        scanf("%d", &num);
        temp=start;
        if(temp->next==NULL)
        {
            start=NULL;
            printf("\n Node deleted!!!");
        }
        else
        {
            while(temp->item!=num)
            {
                ptr=temp;
                temp=temp->next;
            }
            ptr->next=temp->next;
            temp->next->prev=ptr;
            printf("\n Node deleted!! \n ");
       }
       free(temp);
    }
      return start;
}
