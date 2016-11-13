#include<stdio.h>
#include<malloc.h>
struct node
{
   int data;
   struct node*next,*prev;
}*start;

struct node*create_node(int value)
{
   struct node*temp;
   temp=malloc(sizeof(struct node));
   if(temp==NULL)
   {
      printf("memory not allocated");
   }
   else
   {
      temp->data=value;
      temp->next=NULL;
      temp->prev=NULL;
   }
   return temp;
}

void ins_begin()
{
   int value;
   struct node*temp,*p;
   printf("enter value ");
   scanf("%d",&value);
   temp=create_node(value);
   if(start==NULL)
   {
      start=temp;
      start->next=NULL;
      start->prev=NULL;
   }
   else
   {
      p=start;
      start=temp;
      start->next=p;
      start->prev=NULL;
   }
}

void ins_pos()
{
   int value,pos,num=0;
   printf("enter value to be inserted");
   scanf("%d",&value);
   printf("enter position to insert");
   scanf("%d",&pos);
   struct node*temp,*p,*ptr;
   p=create_node(value);
   temp=start;
   while(temp!=NULL)
   {
      temp=temp->next;
      num++;
   }
   if(pos==1)
   {
      if(start==NULL)
      {
         start=p;
         start->next=NULL;
         start->prev=NULL;
      }
      else
      {
         ptr=start;
         start=p;
         start->next=ptr;
         start->prev=NULL;
      }
   }
   else if(pos>1 && pos<=num)
   {
      int i;
      struct node*ptr,*s;
      ptr=start;
      for(i=1;i<pos;i++)
      {
         s=ptr;
         ptr=ptr->next;
      }
   s->next=p;
   p->prev=s;
   p->next=ptr;
   ptr->prev=p;
   }
   else
   {
      printf("position out of range");
   }
}

void display()
{
   struct node*temp;
   if(start==NULL)
   {
      printf("list is empty");
      return;
   }
   temp=start;
   printf("element of lists are\n");
   while(temp!=NULL)
   {
      printf("%d<->",temp->data);
      temp=temp->next;
   }
}

void delete_pos()
{
   int pos,i,num;
   printf("enter position of element to delete");
   scanf("%d",&pos);
   if(pos==1)
   {
      start=start->next;
   }
   else
   {
      struct node*ptr=start;
      while(ptr!=NULL)
      {
         ptr=ptr->next;
         num++;
      }
   if(pos>1 && pos <=num)
   {
      struct node*ptr,*s;
      s=start;
      for(i=1;i<pos;i++)
      {
         ptr=s;
         s=s->next;
      }
      ptr->next=s->next;
      s->next->prev=ptr;
   }
   else
   printf("position out of range");
   }
}

void main()
{
   int ch=1,choice;
   while(ch==1)
   {
      printf("1 to insert at begin, 2 to insert at any position, 3 to delete element at any position, 4  to display list");
      scanf("%d",&choice);
      if(choice<=4)
      {
         switch(choice)
         {
            case 1:ins_begin();
            break;
            case 2:ins_pos();
            break;
            case 3:delete_pos();
            break;
            case 4:display();
            break;
         }
      }
      else
      printf("wrong choice");
      printf("press 1 to continue");
      scanf("%d",&ch);
      if(ch==1)
      continue;
      else
      break;
   }
}
