#include <stdio.h>
#include<stdlib.h>
#define n 5
int front=-1;
int rear=-1;
int arr[n];
int isFull()
{
    if((rear+1)%n==front)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if(front==-1 && rear==-1)
    {
        return 1;
    }
    return 0;
}
void display()
{int i;        
    for(i=front;i!=rear;i=(i+1)%n)
    {
        printf("%d\t",arr[i]);
    }
    printf("%d",arr[i]);
}
void enqueue(int x)
{
    if(isFull())
    {
        printf("Stack is full");
        return;
    }
    else if(isEmpty())
    {
        front=rear=0;
    }
    else
        rear=(rear+1)%n;
    arr[rear]=x;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty!");
        return;
    }
    else if((front+1)%n==rear)
    {
        front=rear=-1;
    }
    else{
        front=(front+1)%n;
    }
}
int main()
{
    int x,c;
    while(1)
    {
        printf("\nEnter\n1.Enqueue\n2.Dequeue\n3.display\n4.exit:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter the value to be pushed:");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
            case 2:dequeue();
                break;
            case 3:display();
                break;
            case 4:exit(0);
            default:printf("Enter the valid input");
            
        
            
        }
    }
    return 0;
}
