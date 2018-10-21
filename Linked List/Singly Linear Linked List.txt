#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE, int);
void Display(PNODE);
int Count(PNODE);
void InsertLast(PPNODE,int);
void DeleteLast(PPNODE);
void DeleteFirst(PPNODE);
void InsertAtPos(PPNODE,int ,int );
void DeleteAtPos(PPNODE ,int);


int main()
{
	int iRet=0;
	PNODE first=NULL;

	InsertFirst(&first,3);
	DeleteLast(&first);
	InsertFirst(&first,2);
	InsertFirst(&first,1);
	InsertFirst(&first,0);
	
	InsertLast(&first,4);
	InsertLast(&first,5);
	InsertLast(&first,6);
	InsertLast(&first,7);
	
	Display(first);

	DeleteLast(&first);
	DeleteFirst(&first);
	DeleteLast(&first);

	Display(first);
	DeleteFirst(&first);
	InsertFirst(&first,97);
	

	InsertAtPos(&first,555,1);
	InsertAtPos(&first,555,6);
	
	InsertAtPos(&first,1000,2);
	Display(first);
	DeleteAtPos(&first,1);
	DeleteAtPos(&first,3);
	Display(first);
	DeleteAtPos(&first,4);
	Display(first);
	iRet=Count(first);
	printf("Number of nodes in link list is :%d\n",iRet);

	return 0;
}

void InsertFirst(PPNODE head, int iValue)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=iValue;
	newn->next=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
}

void Display(PNODE head)
{
	printf("Nodes in a link list are\n");
	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
	printf("NULL\n____________________________________________________________________________________________________________\n");
}

int Count(PNODE head)
{
	int iCnt=0;
	while(head!=NULL)
	{
		iCnt++;
		head=head->next;
	}
	return iCnt;
}

void InsertLast(PPNODE head,int iValue)
{
	PNODE newn=NULL;
	PNODE temp=*head;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=iValue;
	newn->next=NULL;

	if(NULL==(*head))
	{
		*head=newn;
	}
	else
	{
		while((*head)->next!=NULL)
		{
			*head=(*head)->next;
		}
		(*head)->next=newn;
	}
	*head=temp;
}

void DeleteLast(PPNODE head)
{
	PNODE temp=*head;
	if(*head==NULL)
	{
		return;
	}
	else if((*head)->next==NULL)
	{
		free(temp);
		*head=NULL;
	}
	else
	{
		while((temp)->next->next!=NULL)
		{
			temp=(temp)->next;
	
		}
		free(temp->next);
		temp->next=NULL;
	}
}

void DeleteFirst(PPNODE head)
{
	PNODE temp=*head;

	if(*head==NULL)
	{
		return;
	}
	else if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	
	else
	{
		*head=(*head)->next;
		free(temp);
	}
}

void InsertAtPos(PPNODE head,int iValue,int iPos)
{
	int iSize=0,i=0;
	PNODE temp=*head;
	iSize=Count(*head);
	printf("%d",iSize);

	if((iPos<1) || (iPos>iSize+1))
	{
	return;
	}
	if(iPos==1)
	{
		InsertFirst(head,iValue);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(head,iValue);
	}
	else
	{
		PNODE newn=NULL;
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=iValue;
		newn->next=NULL;

		for(i=0;i<(iPos-2);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteAtPos(PPNODE head,int iPos)
{
	int i,iSize=0;
	PNODE temp=*head;
	PNODE temp2=NULL;
	iSize=Count(*head);

	if((iPos<1) || (iPos>iSize))
	{
		return;
	}

	if(iPos==1)
	{
		DeleteFirst(head);
	}
	else if(iPos==iSize)
	{
		DeleteLast(head);
	}
	else
	{
		for(i=1;i<=(iPos-2);i++)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=temp2->next;
		free(temp2);
	}
}


