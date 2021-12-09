#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    
};

struct node* head=NULL;
struct node* newNode;




void insertAThead(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=head;
    head=newNode;
}

void insertATrear(int x)
{   newNode=(struct node*) malloc(sizeof(struct node));
    struct node* temp=head;
    newNode->data=x;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    
    
}

int size()
{
    struct node* temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

void insertATpos(int x,int pos)
{   int len=size();
    if(len==0)
    {insertAThead(x);
        return;
        
    }
    if(pos>len+1)
    {   printf("-----::position is out of range::----\n");
        return;
    }
    if(pos==1)
    {
        insertAThead(x);
        return;
    }
    if(pos==len+1)
    {
        insertATrear(x);
        return;
    }
    newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=x;
    struct node* temp=head;
    for(int i=1;i<pos-1;i++)
    {   
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
}

void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
    
}
int main()
{
    int x,ch,pos;
     printf("\nEnter::\n1.insertATpos\n2.deleteATpos\n3.display\n4.exit the program\n");
    while(1)
    {   printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element and position to insert in linked list:");
                scanf("%d %d",&x,&pos);
                insertATpos(x,pos);
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