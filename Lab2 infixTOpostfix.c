#include <stdio.h>
#include<ctype.h>
#define n 20
char arr[n];
int top=-1;


void push(char ch)
{
    arr[++top]=ch;
}
int pop()
{   int ele=arr[top];
    top--;
    return ele;
}

int pr(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char infix[50];
    
    char postfix[50],ch,ele;
    int i=0,k=0;
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {   
        if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')')
        {
            while(arr[top]!='(' )
            {   postfix[k++]=pop();
                
            }
            ele=pop();
        }
        else{
            while(pr(arr[top])>=pr(ch))
            {   postfix[k++]=pop();
            
                
            }
            push(ch);
        }
        
        
    }
    while(arr[top]!='#')
        {
            postfix[k++]=pop();
        }
     postfix[k]='\0';   
     printf("res=%s",postfix);
    
      return 0;
}