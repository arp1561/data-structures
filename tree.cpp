#include<bits/stdc++.h>
using namespace std;
struct node
{
      int val;
      struct node *left, *right;
};
struct node *root;
struct node *insert(struct node *r,int data);
void inorder(struct node *r);
void postorder(struct node *r);
void preorder(struct node *r);

int main()
{
      root = NULL;
      int i,n,v;
      printf("Enter the number of values :");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            printf("Data %d :",i+1);
            scanf("%d",&v);
            root = insert(root,v);
      }
      printf("Inorder :");
      inorder(root);
      printf("\nPreorder :");
      preorder(root);
      printf("\nPostorder :");
      postorder(root);
}
struct node *insert(struct node *r,int data)
{
      if(r==NULL)
      {
            r = (struct node*)malloc(sizeof(struct node));
            r->val = data;
            r->left = NULL;
            r->right = NULL;

      }
      else if(data<r->val)
      {
            r->left = insert(r->left,data);
      }
      else
      {
            r->right = insert(r->right,data);
      }
      return r;
}
void inorder(struct node *r)
{
      if(r!=NULL)
      {
            inorder(r->left);
            printf(" %d ",r->val);
            inorder(r->right);
      }

}
void preorder(struct node *r)
{
      if(r!=NULL)
      {
            printf(" %d ",r->val);
            preorder(r->left);
            preorder(r->right);
      }
}
void postorder(struct node *r)
{
      if(r!=NULL)
      {
            postorder(r->left);
            postorder(r->right);
            printf(" %d ",r->val);
      }

}
