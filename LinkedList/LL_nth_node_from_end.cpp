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

int endnode_bruteforce(struct node **head, int n)
{
	int count=0;//count number of nodes
	//copy head to temp
	struct node *temp=*head;
	if(temp==NULL)
	{
		cout<<"List is empty";
		return -1;
	}
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	count++;
	if(n>count)
	{
		cout<<"List does not have"<<n<<"nodes";
		return -1;
	}
	else if(n<1)
	{
		cout<<"Invalid number"<<endl;
		return -1;
	}
	//temp points to head
	temp=*head;
	while(temp->next!=NULL && count-->n)
		temp=temp->next;
	return temp->data;
}

int endnode_doubleptr(struct node **head, int n)
{
	struct node *temp=*head;
	//create 2 pointers
	struct node *ptr_first=temp, *ptr_second=temp;
	if(temp==NULL)
	{
		cout<<"List is empty";
		return -1;
	}
	if(n<0)
	{
		cout<<"Invalid number";
		return -1;
	}
	while(ptr_first->next!=NULL && --n>0)
	{
		ptr_first=ptr_first->next;
		cout<<"N:"<<n<<"\tptr1_data"<<ptr_first->data<<endl;
	}	
	if(n>0)
		{
			cout<<"List is smaller";
			return -1;
		}
	while(ptr_first->next!=NULL)
	{
		ptr_first=ptr_first->next;
		ptr_second=ptr_second->next;
		cout<<"ptr2_data:"<<ptr_second->data<<endl;
	}
	return ptr_second->data;
	
}

//lookup using arrays, can be done with hash as well
int endnode_lookup(struct node **head, int n)
{
	int arr[15];
	struct node *temp=*head;
	if(temp==NULL)
	{
		cout<<"List is empty";
		return -1;
	}
	int i=0;
	while(temp->next!=NULL)
	{
		arr[i++]=temp->data;
		temp=temp->next;
	}
	arr[i]=temp->data;
	return arr[i-n+1];
	
}

int main()
{
  struct node *head;
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
  cout<<endnode_bruteforce(&head,1)<<endl;
  cout<<endnode_lookup(&head,5);
  cout<<endnode_doubleptr(&head,3);
}
