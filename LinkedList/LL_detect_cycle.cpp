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

void delete_node(struct node **head, int data)
{
	//copy to temp node
	struct node *temp=new node();
	temp=*head;
	//check if list is empty
	if(temp==NULL)
	{
		return;
	}
	//check for begin node
	if(temp->data==data)
	{
		//point head to next node
		*head=temp->next;
		//unlink temp & release
		temp->next=NULL;
		delete temp;
		return void();
	}
	//traverse
		//create a prev node
	struct node *prev=temp;
	while(temp->next!=NULL && temp->data<data)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp->data==data)
	{
		//end of list
		if(temp->next==NULL)
		{
			prev->next=NULL;
			delete temp;
			return void();
		}
		//middle of list
		prev->next=temp->next;
		temp->next=NULL;
		delete temp;
		return void();
	}
	else
	cout<<endl<<"End of list."<<data<<" not found"<<endl;
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

int floyd(struct node **head)
{
	struct node *temp=*head;
	struct node *ptr1=temp->next->next, *ptr2=temp;
	while(ptr1->next!=NULL && ptr1->data!=ptr2->data)
	{
		if(ptr1->next->next!=NULL)
		{
			ptr1=ptr1->next->next;
			ptr2=ptr2->next;	
		}
		else
		break;
	}
	return (ptr1->next==NULL || ptr1->next->next==NULL) ? -1:1;
}

int main()
{
  struct node *head;
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
  //introduce cycle 
  struct node *newnode=new node();
  newnode->data=50;
  newnode->next=head->next->next->next;
  struct node *temp=head;
  while(temp->next!=NULL)
  temp=temp->next;
  temp->next=newnode;
  //
  floyd(&head)>0? cout<<"Cycle detected": cout<<"No loop";
  
}
