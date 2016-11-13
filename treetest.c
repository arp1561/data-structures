#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left, *right;
};
struct node *root=NULL;
struct node *insert(struct node *r,int val);
void inorder(struct node *r);
void postorder(struct node *r);
void preorder(struct node *r);

int main()
{
    int i,n,v;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Data %d :",i+1);
        scanf("%d",&v);
        root = insert(root,v);
    }
    inorder(root);

}
struct node *insert(struct node *r, int val)
{
    if(r==NULL)
    {
        r  = (struct node *)malloc(sizeof(struct node));
        r->val = val;
        r->left=NULL;
        r->right=NULL;
    }
    else if(val<r->val)
        r->left = insert(r->left,val);
    else
        r->right = insert(r->right,val);
    return r;
}
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d",r->val);
        inorder(r->right);
    }
}
