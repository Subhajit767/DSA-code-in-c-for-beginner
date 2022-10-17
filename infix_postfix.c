#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isOperator(char ab)
{
    if(ab=='+' || ab=='-' || ab=='*' || ab=='/')
    return 1;
    else
    return 0;
}

int precedence(char sa)
{
    if(sa=='*' || sa=='/')
    return 2;
    else if(sa=='+' || sa=='-')
    return 1;
    else
    return 0;
}

char stackTop(struct stack *sp)
{
    return (sp->arr[sp->top]);
}

void push(struct stack *sp, char data)
{
    if(sp->top==sp->size-1)
    {
        printf("Stack Overflow! Cannot push %c into the stack.\n",data);
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=data;
    }
}

char pop(struct stack *ptr)
{
    if(ptr->top==-1)
    printf("Stack Underflow!");
    else
    {
        int data=ptr->arr[ptr->top];
        ptr->top--;
        return (data);
    }
}

int isEmpty(struct stack *sp)
{
    if(sp->top==-1)
    return 1;
    else
    return 0;
}

char* infixtopostfix(char* infix)
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=20;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char *postfix=(char *)malloc(strlen(infix)+1 * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else if(precedence(infix[i])>precedence(stackTop(sp)))
        {
            push(sp,infix[i]);
            i++;
        }
        else
        {
            postfix[j]=pop(sp);
            j++;
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char exp[]="x-y/z-k*d";
    printf("The required postfix expression is %s\n",infixtopostfix(exp));
    return 0;
}