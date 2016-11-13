#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
      int val;
      struct node *next;
};
struct node *head = NULL;
struct node *curr = NULL;

struct node* create_list(int val)
{
      printf("\nCreating list with headnode as [%d]\n",val);
      struct node *ptr = (struct node*)malloc(sizeof(struct node));
      if(NULL==ptr)
      {
            printf("\n Node creation failed \n");
            return NULL;
      }
      ptr->val = val;
      ptr->next = NULL;

      head = curr = ptr;
      return ptr;
}
struct node* add_to_list(int val,bool add_to_end)
{
      if(NULL==head)
            return (create_list(val));
      if(add_to_end)
            printf("\nAdding node to end of the list with value [%d]",val);
      else
            printf("\nAdding node to the beginning of the list [%d]",val);

      struct node *ptr = (struct node*)malloc(sizeof(struct node));

      if(NULL == ptr)
      {
            printf("\nNode creation failed \n");
            return NULL;
      }
      ptr->val = val;
      ptr->next = NULL;

      if(add_to_end)
      {
            curr->next = ptr;
            curr=ptr;
      }
      else
      {
            ptr->next = head;
            head = ptr;
      }
      return ptr;
}

void print_list()
{
      struct node *ptr = head;
      printf("\n--------Printing list---------\n\n");
      while(ptr!=NULL)
      {
            printf("[%d]->",ptr->val);
            ptr=ptr->next;
      }
      printf("NULL\n\n-------End of list------------\n");
}
void delete_from_front()
{
    	struct  node *next_node = NULL;
      if(head==NULL)
		return;
      next_node=head->next;
      free(head);
      head = next_node;

}
void delete_from_end()
{
	struct node *temp,*last;
	temp=head;
	last = temp;
	while(temp != NULL && temp->next!=NULL)
	{
	    last=temp;
	    temp=temp->next;
	}
	if(last == temp)
	{
 	   free(temp);
	    head=NULL;
	} 
	else 
	{
	    free(last->next);
	    last->next = NULL;
	}
}
int main()
{
      int i=0,ret=0,choice=0,num;
      struct node *ptr = NULL;

      print_list();
/*
      for(i=0;i<5;i++)
      {
            add_to_list(i,true);
      }
      for(i=5;i<10;i++)
            add_to_list(i,false);

      print_list();
	delete_from_end();
      print_list();
*/

      while(1)
      {
            printf("1. Insert at the beginning \n2. Insert at the end \n3. Delete from the beginning \n4. Delete from the end \n5. Display\nEnter your option :");
            scanf("%d",&choice);
            if(choice==1)
            {
                  printf("Enter the number :");
                  scanf("%d",&num);
                  add_to_list(num,false);
                  printf("\n\n");
            }
            else if(choice==2)
            {

                  printf("Enter the number :");
                  scanf("%d",&num);
                  add_to_list(num,true);
                  printf("\n\n");
            }
            else if(choice==3)
            {
                 delete_from_front();
                 printf("\n\n");
            }
            else if(choice==4)
            {
                  delete_from_end();
                  printf("\n\n");
             }
            else if(choice==5)
            {
                  print_list();
                  printf("\n\n");
            }
            else
                  break;
      }





 
}
