#include<iostream>
#include<queue>

using namespace std;

struct node
{
  int data;
  struct node *left, *right;
};

struct node *newNode(int data)
{
  struct node *temp = new node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void print(struct node *node)
{
  if(node != NULL)
  {
    print(node->left);
    cout<<node->data<<"  ";
    print(node->right);
  }
}

void levelOrderTraversal(struct node *temp)
{
    if(temp == NULL)
    {
      return;
    }
    queue<node*> levelQueue;
    levelQueue.push(temp);
    while(!levelQueue.empty())
    {
      struct node *temp = levelQueue.front();
      cout<<temp->data<<"  ";
      if(temp->left != NULL)
      {
        levelQueue.push(temp->left);
      }
      if(temp->right != NULL)
      {
        levelQueue.push(temp->right);
      }
      levelQueue.pop();
    }
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  cout<<"Inorder traversal"<<endl;
  print(root);
  cout<<endl<<"Level order traversal"<<endl;
  levelOrderTraversal(root);
  return 0;
}
