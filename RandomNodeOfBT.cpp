#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int a;
    Node *left, *right;
    int children;
};

Node *newNode(int a)
{

    Node *temp = new Node;
    temp->a = a;
    temp->right = NULL;
    temp->left = NULL;
    temp->children = 0;
    return temp;
}

int getElements(Node *node)
{
    if (!node)
    {
        return 0;
    }
    return (getElements(node->left) + 1 +getElements(node->right));
}

void insertChildrenCount(Node *root)
{
    if (!root)
    {
        return;
    }

    root->children = getElements(root)-1;
    insertChildrenCount(root->left);
    insertChildrenCount(root->right);
}

int getChildren(Node *root){
    if(!root){
        return 0;
    }
    return root->children +1;
}

int randomNodeUtil(Node *root, int count){

    if(!root){
        return 0;
    }
    if(count == getChildren(root->left)){
      return root->a;
    }

    if(count < getChildren(root->left)){
        return randomNodeUtil(root->left,count);
    }
    return randomNodeUtil(root->right,count-getChildren(root->left)-1);
}

int randomNode(Node *root){
    srand(time(0));

    int count =rand() % (root->children +1);

    return randomNodeUtil(root,3);
}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->right = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    insertChildrenCount(root);
    
    cout << randomNode(root) << endl;

    return 0;
}