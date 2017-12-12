#include<iostream>

using namespace std;

struct node{
  int data;
  struct node *next;
};

struct node* insert_head(struct node **head, int data)
{
  struct node *newnode=new node();
  newnode->data=data;
  newnode->next=NULL;

  if(*head==NULL)
  {
    *head=newnode;
    return *head;
  }

  newnode->next=*head;
  *head=newnode;
  return newnode;

}

void insert_begin(struct node **head, int data)
{
	//new node
	struct node *newnode=new node();
	newnode->data=data;
	newnode->next=NULL;
	//link
	newnode->next=*head;
	*head=newnode;
}

void insert_end(struct node **head, int data)
{
	//create new node
	struct node *newnode= new node();
	newnode->data=data;
	newnode->next=NULL;
	//copy head to a temp node
	struct node *temp=*head;
	//link
	while((temp)->next!=NULL)
		temp=(temp)->next;
	temp->next=newnode;
}

void insert_middle(struct node **head, int data)
{
	//create new node
	struct node *newnode= new node();
	newnode->data=data;
	newnode->next=NULL;
	//copy head to temp
	struct node *temp=*head, *prev=NULL;
	//traverse
	while(temp->data<data)
	{
		prev=temp;
		temp=temp->next;
		
	}	
	temp=prev;
	//link
	newnode->next=temp->next;
	temp->next=newnode;
}

void print(struct node *node)
{
	while(node->next!=NULL)
	{
		cout<<node->data<<endl;
		node=node->next;
	}
	cout<<node->data<<endl;
}

void reverse_print(struct node *node)
{
	if(node==NULL)
	{
		cout<<"List is empty";
		return ;
	}
	
	if(node->next==NULL)
	{
		cout<<node->data<<endl;
	}
	if(node->next!=NULL)
	{
		reverse_print(node->next);
		cout<<node->data<<endl;
	}
}

void oddeven(struct node *head)
{
	struct node *temp=head;
	struct node *ptr1=temp->next->next, *ptr2=temp;
	if(head==NULL)
	{
		cout<<"List is empty";
		return ;
	}
	while(ptr1->next!=NULL)
	{
		if(ptr1->next->next!=NULL)
		{
			ptr1=ptr1->next->next;
			ptr2=ptr2->next;
		}
		else
		break;
	}
	if(ptr1->next==NULL)
	cout<<"List is odd";
	else
	cout<<"List is even";
}

int main()
{
  struct node *head=NULL;
  //head=insert_head(&head,10);
  insert_begin(&head,5);
  insert_begin(&head, 2);
  insert_begin(&head,1);
  insert_end(&head,15);
  insert_end(&head,150);
  insert_end(&head,1500);
  insert_middle(&head,100);
  insert_middle(&head,200);
  insert_middle(&head,300);
  print(head);
  cout<<"Calling method:"<<endl;
  oddeven(head);
  cout<<"Control in main function"<<endl;

  
}
