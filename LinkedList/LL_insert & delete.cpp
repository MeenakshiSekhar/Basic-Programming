#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **head, int data)
{
	struct node *newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	if(*head == NULL)
	{
		*head = newnode;
		return;
	}
	struct node *temp = new node();
	temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	return;
}

void deletenode(struct node **head, int data)
{
	struct node *temp = *head;
	struct node *ptr = temp;
	{
		/* data */
	};
	if(temp->data == data)
	{
		*head = temp->next;
		temp->next = NULL;
		free(temp);
		return;
	}
	while(temp->next != NULL)
	{
		ptr = temp;
		temp = temp->next;
		if(temp->data == data)
		{
			ptr->next = temp->next;
			temp->next = NULL;
			free(temp);
			return;
		}
	}
	return;
}

void print(struct node *node)
{
	while(node != NULL)
	{
		cout<<node->data<<endl;
		node = node->next;
	}
}

int main()
{
	struct node *head=NULL;
	insert(&head, 10);
	insert(&head, 100);
	insert(&head, 1);
	insert(&head, 110);
	insert(&head, 101);
	insert(&head, 1011);
	insert(&head, 1101);
	insert(&head, 110);
	insert(&head, 11);
	deletenode(&head, 1011);
	deletenode(&head, 10);
	print(head);
	return 0;
}
