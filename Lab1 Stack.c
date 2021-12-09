#include <stdio.h>
#include<conio.h>
#define n 10
int top=-1;
int arr[n];
void push(int val)
{
    if(top==n-1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    arr[top]=val;
}
void pop()
{
    if(top==-1)
    {
        printf("stack is Empty");
        return;
    }
    top--;
}
void display()
{   int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int a,val;
    
    printf("Enter 1.push\n2.pop\n3.display\n0.exit the program\n");
    scanf("%d",&a);
    while(a!=0)
    {switch(a)
    {
        case(1):
        {
            printf("Enter the value to be pushed:");
            scanf("%d\n",&val);
            push(val);
            break;
        }
        case(2):
        {
            
            pop();
            break;
        }
        case(3):
        {
            
            display();
            break;
        }
        default:
            printf("Enter a valid number\n");
    }
        printf("Enter 1.push\n2.pop\n3.display\n0.exit the program\n");
        scanf("%d",&a);
    }
    return 0;
    
}