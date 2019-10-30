
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node*root= NULL;
int len;
void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void delete(void);
void main()
{
	int ch;
	while(1)
	{
		printf("Single linked list operations:\n");
		printf("1. Append\n");
		printf("2. Add at beginning\n");
		printf("3. Add at after\n");
		printf("4. Length of list\n");
		printf("5. Display the list\n");
		printf("6. Delete\n");
		printf("7. Quit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : append();
			         break;
			case 2 : addatbegin();
			         break;
			case 3 : addatafter();
			         break;
			case 4 : len=length();
			         printf("Length is : %d\n\n\n",len);
			         break;
			case 5 : display();
			         break;
			case 6 : delete();
			         break;
			case 7 : exit(1);
			default : printf("Invalid option \n\n");
		}
	}
}
void append()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data : ");
	scanf("%d",&temp->data);
	temp->link= NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->link !=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int length()
{
	int count =0;
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
void display()
{
	struct node* temp;
	temp=root;
	if(temp==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
		printf("\n\n");
	}
}
void addatafter(void)
{
	struct node*temp,*p;
	int loc,len,i=1;
	printf("Enter location : ");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("Invalid Location\n");
		printf("Currently list is having only %d nodes",len);
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the node data : ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;   //Right connection first
		p->link=temp;    //left connection
		
	}
}
void delete(void)
{
	struct node*temp;
	int loc;
	printf("Enter location to delete : ");
	scanf("%d",&loc);
	if(loc>length())
	{
		printf("Invalid location\n");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node*p=root,*q;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;  
		q->link=NULL; 
		free(q);
	}
}
void addatbegin(void)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data :");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
	
}

