#include<bits/stdc++.h>
using namespace std;



class Node{
public:
    Node *left;
    int data;
    Node *right;

};

Node *root = NULL;

Node *createNode(int data)
{
    Node *new_node =  new Node();

    if(!new_node)
    {
        cout<<"Memory error";
        return NULL;
    }
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}


Node *insertion(Node *root, int data)
{

    //queue<Node *> q;
    if(root==NULL)
    {
        root = createNode(data);
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = createNode(data);
            return root;
        }

        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = createNode(data);
            return root;
        }

    }
}


Node * inorder(Node * temp)
{
    if(temp==NULL)
      {
            return NULL;
      }
    inorder(temp->left);
    cout<<temp->data<<" ";
     inorder(temp->right);
}
int main()
{
    Node *root = createNode(10);
    root->left = createNode(11);
    root->right = createNode(9);
    root->left->left = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
   // //root->left = createNode(11);
 int key;
    cout<<"Enter the key : ";
    cin>>key;
    insertion(root, key);

    inorder(root);
    return 0;
}
