#include <stdio.h>
#include<stdlib.h>
#define max 5
int front=-1,rear=-1;
int pri_queue[max];

void check(int data)
{
    int i,j;
    for(i=0;i<=rear;i++)
    {
        if(data>=pri_queue[i])
        {
            for(j=rear+1;j>i;j--)
            {
                pri_queue[j]=pri_queue[j-1];
            }
            pri_queue[i]=data;
            return;
        }
    }
    pri_queue[i]=data;
}

void insert_by_priority(int data)
{
    if(rear>=max-1)
    {
        printf("\n Queue overflow");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        pri_queue[rear]=data;
        return;
    }
    else
    {
        check(data);
    }
    rear++;
}

void delete_by_priority(int data)
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty");
        return;
        
    }
    for(i=0;i<=rear;i++)
    {
        if(data==pri_queue[i])
        {
            for(;i<rear;i++)
            {
                pri_queue[i]=pri_queue[i+1];
            }
            pri_queue[i]=-99;
            rear--;
            if(rear==-1)
            {
                front=-1;
                
            }
            return;
        }
        
    }
    printf("Not found %d",data);
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",pri_queue[i]);
    }
    
}

int main()
{   int n,ch;
    printf("\n1.insert\n2.pop\n3.display\n4.exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to be inserted:");
                scanf("%d",&n);
                insert_by_priority(n);
                break;
            case 2:
                printf("Enter the val to be deleted:");
                scanf("%d",&n);
                delete_by_priority(n);
                break;
                
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        
        }
    }
    

    return 0;
}
