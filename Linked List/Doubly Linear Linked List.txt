#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;	
typedef struct node** PPNODE;

void InsertFirst(PPNODE ,int );
void Display(PNODE);
int Count(PNODE);
void InsertLast(PPNODE,int);
void DisplayBackward(PNODE);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE,int,int);
void DeleteAtPos(PPNODE,int);

int main()
{
	PNODE first=NULL;
	int iRet=0;
	
	InsertFirst(&first,10);
	InsertFirst(&first,55);
    InsertLast(&first,20);
	Display(first);
	InsertFirst(&first,600);
	InsertFirst(&first,500);
    InsertLast(&first,200);
	
	
	iRet=Count(first);
	printf("\n%d\n",iRet);
	
	DeleteFirst(&first);
	DisplayBackward(first);
	iRet=Count(first);
	printf("\n%d\n",iRet);
	InsertAtPos(&first,3,101);
	DeleteFirst(&first);
	DeleteLast(&first);
	Display(first);

	DeleteAtPos(&first,3);
	DeleteFirst(&first);
	DeleteLast(&first);
	Display(first);

}

void InsertFirst(PPNODE head,int iValue)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=iValue;
	newn->next=NULL;
	newn->prev=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else 
	{
		newn->next=*head;
		(*head)->prev=newn;
		*head=newn;
	}
}

void Display(PNODE head)
{
	if(head!=NULL)
	{
		while(head!=NULL)
		{
			printf("|%d|->",head->data);
			head=head->next;
		}
		printf("NULL\n");
	}
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
	PNODE temp=*head;
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=iValue;
	newn->next=NULL;
	newn->prev=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
}

void DisplayBackward(PNODE head)
{
	PNODE temp=head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}

	while(temp != NULL)
	{
		printf("|%d|->",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
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
		free((*head)->prev);
		(*head)->prev=NULL;
	}
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
		free(*head);
		*head=NULL;
	}
	else
	{
		while(temp->next!= NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);

	}
}

void InsertAtPos(PPNODE head, int iPos, int iValue)
{
	PNODE temp=NULL;
	int i=0;
	int iSize=Count(*head);

	if((iPos<0) || (iPos>(iSize+1)))
	{
		return;
	}
	if(iPos==1)
	{
		InsertFirst(head,iValue);
	}
	else if(iPos==(iSize+1))
	{
		InsertLast(head,iValue);
	}
	else
	{
		PNODE newn=NULL;
		temp=*head;
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=iValue;
		newn->next=NULL;
		newn->prev=NULL;

		for(i=1;i<=(iPos-2);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		newn->prev=temp;
	}
		
}

void DeleteAtPos(PPNODE head, int iPos)
{
	PNODE temp=*head;
	PNODE temp2=NULL;
	int i=0;
	int iSize=Count(*head);

	if((iPos<0) || (iPos>(iSize+1)))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteFirst(head);
	}
	else if(iPos==(iSize+1))
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
		temp->next=temp->next->next;
		free(temp2);
		temp2=NULL;
		temp->next->prev=temp;	
	}
		
}
