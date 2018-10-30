#include<iostream>

using namespace std;
 
struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class stack
{
public:
	PNODE head;

public:
	stack();
	~stack();

	void Push(int);
	int Pop();
	void Display();
	int Count();

};

stack :: stack()
{
	head=NULL;
}


stack :: ~stack()
{
	cout<<"Inside the Distructor";
}


void stack:: Push(int iValue)
{
	PNODE newn=NULL;

	newn=new NODE;

	newn->data=iValue;
	newn->next=NULL;

	if(head==NULL)
	{
		head=newn;
	}
	else
	{
		newn->next=head;
		head=newn;
	}
}

int stack:: Pop()
{
	PNODE temp=head;
	int iRet=0;

	if(head==NULL)
	{
		return -1;
	}
	else
	{
		head=head->next;
	}
	iRet=temp->data;
	free(temp);

	return iRet;
}

void stack:: Display()
{
	PNODE temp=head;
	while(temp!=NULL)
	{
		cout<<"|->|"<<temp->data;
		temp=temp->next;
	}
}

int stack:: Count()
{
	int iCnt=0;
	PNODE temp=head;

	while(temp!=NULL)
	{
		iCnt++;
		temp=temp->next;
	}
	return iCnt;
}

int main()
{
	stack obj1;
	obj1.Push(10);
	obj1.Push(20);
	obj1.Push(30);
	obj1.Push(55);
	obj1.Pop();
	obj1.Display();
	cout<<endl<<obj1.Count();

	return 0;
}
