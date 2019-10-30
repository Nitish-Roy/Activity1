#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;
void push(int);
int pop(void);
int isFull(void);
int isEmptyvoid();
void traverse(void);
void peek(void);
void main(void)
{
	int ch;
	int item;
	while(1)
	{
		printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. Transverse \n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
    	{
    		case 1 : printf("Enter element to push : ");
    		         scanf("%d",&item);
			         push(item);
			         break;
    		case 2 : item=pop();
    		         if(item==0)
    		         {
    		         	printf("stack is underflow \n");
					 }
					 else
					 {
					 	printf("popped item is :%d",item);
					 }
					 break;
    		case 3 : peek();
    		         break;
    		case 4 : traverse();
    		         break;
    		case 5 : exit(0);
    		default: printf("Invalid input \n\n"); 
		}
	}
}
void push(int ele )
{
	if(isFull())
	{
		printf("Stack is already full \n");
	}
	else
	{
		top++;
		stack[top]=ele;
		printf("%d Inserted\n",ele);
	}
}
int isFull()
{
	if(top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return stack[top--];
	}
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void peek()
{
	if(isEmpty())
	{
		printf("No elements in the stack \n");
	}
	else
	{
		printf("peek element is : %d \n",stack[top]);
	}
}
void traverse()
{
	if(isEmpty())
	{
		printf("No elements in the stack \n");
	}
	else
	{
		int i;
		printf("Elements in the stack are : ");
		for(i=0;i<=top;i++)
		{
			printf("%d\n",stack[i]);
		}
	}
}
