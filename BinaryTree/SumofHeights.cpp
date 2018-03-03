#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *right, *left;
};


int max(int a, int b)
{
    return a > b ? a : b;
}

int maxHeight(struct node *temp)
{
	if(temp == NULL)
	{
		return -1;
	}
	return 1+max(maxHeight(temp->right), maxHeight(temp->left));
}

int sumofheights(struct node *temp)
{

  if(temp == NULL)
  {
    return 0;
  }
  return sumofheights(temp->left)+maxHeight(temp)+sumofheights(temp->right);
}

int* returnValue(struct node *temp, int *arr)
{
arr[0]=maxHeight(temp);
arr[1]=sumofheights(temp);
return arr;
}

struct node* construct_treeHEAD(struct node *temp, int data)
{
        if(temp == NULL)
        {
            struct node *newnode = new node();
            newnode->data = data;
            newnode->right = newnode->left = NULL;
            return newnode;
        }
        else if(temp->data < data)
        {
              temp->right = construct_treeHEAD(temp->right, data);
        }
        else if(temp->data > data)
        {
              temp->left = construct_treeHEAD(temp->left, data);
        }
        return temp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    struct node *head=NULL;
    int n;
    cin>>n;
    int arr[n];
    for(int arr_i=0; arr_i<n; arr_i++)
        cin>>arr[arr_i];
    for(int i=0; i<n; i++)
    {
        if(head == NULL)
            head = construct_treeHEAD(head, arr[i]);
        else
            construct_treeHEAD(head, arr[i]);
    }
    int* max_ht;
    int a[2]={0};
    max_ht=returnValue(head, a);
    cout<<max_ht[0]<<endl<<max_ht[1];
    return 0;
}
