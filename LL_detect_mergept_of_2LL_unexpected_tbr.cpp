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

int print(struct node *node)
{
	int count=0;
	while(node->next!=NULL)
	{
		count++;
		cout<<node->data<<endl;
		node=node->next;
	}
	count++;
	cout<<node->data<<endl<<"end of print"<<endl;
	return count;
}

void merge(struct node *head1, struct node *head2)
{
	cout<<"checker";
	struct node *ptr1=head1, *ptr2=head2;
	int count1=0, count2=0, diff=0;
	if(ptr1==NULL || ptr2==NULL)
	{
		cout<<"no list";
		return ;
	}
	while(ptr1->next!=NULL)
	{
		count1++;
		ptr1=ptr1->next;
	}
	while(ptr2->next!=NULL)
	{
		count2++;
		ptr2=ptr2->next;
	}
	cout<<"check";
	ptr1=head1;
	ptr2=head2;
	if(count1>count2)
	{
		while(count1--==count2)
		{
			ptr1=ptr1->next;
		}
		while(ptr1->data!=ptr2->data)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		cout<<ptr1->data;
	}
	else
	{
		while(count2--==count1)
		{
			ptr2=ptr2->next;
		}
		while(ptr1->data!=ptr2->data)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		cout<<ptr1->data;
	}
	
}

int main()
{
  struct node *head;
  cout<<"test";
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
  
  struct node *newnode=new node();
  struct node* trial=head;
  newnode->data=25;
  newnode->next=NULL;
  struct node *head2=newnode;
  struct node *temp=new node();
  temp->data=50;
  temp->next=head->next->next->next->next->next;
  head2->next=temp;
  cout<<"Second list";
  int count1=print(head);
  int count2=print(head2);
  cout<<"Merge node:";
  //merge(head, head2);
  //print(head);
  struct node *ptr1=head, *ptr2=head2;
  cout<<"count1:"<<count1<<" count2:"<<count2<<endl;
  if(count1>count2)
	{
		while(count1!=count2)
		{
			count1--;
			ptr1=ptr1->next;
		}
		while(ptr1->data!=ptr2->data)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		cout<<ptr1->data;
	}
	else
	{
		while(count2!=count1)
		{
			count2--;
			ptr2=ptr2->next;
		}
		while(ptr1->data!=ptr2->data)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		cout<<ptr1->data;
	}
  return 0;
}
