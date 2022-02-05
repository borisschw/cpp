#include <iostream>
#include <vector.h>
#include <cmath>
using namespace std;
void in_order(struct node*);


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* new_node(int data)
{
  struct node* node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void in_order(struct node* node)
{
    if(node == NULL)
      return;
    printf("%d\n",node->data);
    in_order(node->left);
    in_order(node->right);
}

int main()
{
  struct node * root = new_node(4);
  /*------*/
  root->left = new_node(2);
  root->right = new_node(6);
  /*------*/
  root->left->left = new_node(1);
  root->left->right = new_node(3);

  root->right->left = new_node(5);
  root->right->right = new_node(7);
  /*------*/
  in_order(root);

}


