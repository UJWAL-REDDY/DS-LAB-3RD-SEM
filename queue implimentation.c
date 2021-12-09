#include <stdio.h>
#include<conio.h>
#define n 10
int arr[n];
int s=-1;
int r=-1;

int Isfull()
{
    if(r==(n-1))
    {
        return 1;
    }
    return 0;
    
}
int Isempty()
{
    if(s==-1 && r==-1)
    {
        return 1;
    }
    return 0;
    
}
void Enqueue(int x)
{
    if(Isfull())
    {
        printf("Queue is full");
        return;
    }
    else if(Isempty())
    {
        s=0;
        r=0;
    }
    else
    {
        r++;
    }
    arr[r]=x;
}
void Dequeue()
{
    if(Isempty())
    {
        printf("No element in queue ");
        return;
    }
    else if(s==r)
    {
        s=-1;
        r=-1;
    }
    else{
        s++;
    }
    
}
void display()
{
    for(int i=s;i<=r;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{   
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Dequeue();
    Enqueue(50);
    display();
    return 0;
}