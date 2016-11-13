#include<stdio.h>
#include<stdbool.h>
#define MAX 6
int array[MAX];
int count=0;
int peek()
{
    return array[count-1];
}
bool isEmpty()
{
    return count==0;
}
bool isFull()
{
    return count==MAX;
}
int size()
{
    return count;
}
void insert(int data)
{
    int i=0;

    if(!isFull())
    {
        if(count==0)
            array[count++]=data;
        else
        {
            for(i=count;i>=0;i--)
            {
                if(data>array[i])
                    array[i+1]=array[i];
                else
                    break;
            }
            array[i+1]=data;
            count++;
        }
    }
}
int main()
{
    int i=0;
    insert(3);
    insert(5);
    insert(9);
    insert(1);
    insert(12);
    insert(15);
    for(i=0;i<count;i++)
        printf(" %d ",array[i]);
}
