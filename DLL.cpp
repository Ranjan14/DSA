//Doubly linked list

#include<bits/stdc++.h>
using namespace std;

int len;
int Length();
class Node{
public:
    int data;
    Node *Llink;
    Node *Rlink;
};

Node *head = NULL;


void InsertFront()
{
    int ele;
    Node *new_node = new Node();
    new_node->Rlink=NULL;
    new_node->Llink=NULL;
    cout<<"Enter the element : ";
    cin>>ele;
    new_node->data = ele;
    new_node->Rlink = head;
    if(head!=NULL)
        head->Llink = new_node;

    head = new_node;
}


void InsertBack()
{
    int ele;
    Node *new_node = new Node();
    cout<<"Enter the element : "<<endl;
    cin>>ele;
    new_node->data=ele;
    new_node->Rlink=NULL;
    new_node->Llink=NULL;
    if(head==NULL)
    {
        head = new_node;
        return;
    }
    Node *prev=head;
    while(prev->Rlink!=NULL)
    {
        prev=prev->Rlink;
    }
    prev->Rlink = new_node;
    new_node->Llink = prev;
}

void InsertAfter()
{
    int ele,pos;
    Node *new_node = new Node();
    cout<<"Enter the Element : ";
    cin>>ele;
    cout<<"Enter the position : "<<endl;
    cin>>pos;
    new_node->data=ele;
    new_node->Llink=NULL;
    new_node->Rlink=NULL;
    Node *prev = head;
    Node *next;
    if(pos < 1 || pos >Length())
    {
        cout<<"Invalid position "<<endl;
    }
    else
    {
      pos=pos-2;
      while(pos--)
      {
          prev=prev->Rlink;
      }
      next = prev->Rlink;

      new_node->Rlink=next;
      next->Llink = new_node;
      new_node->Llink=prev;
      prev->Rlink=new_node;
    }

}

int Length()
{
    int Count=0;
    Node *temp = head;
    if(temp==NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            Count++;
            temp=temp->Rlink;
        }
        return Count;
    }
}


void show()
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else{
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->Rlink;
        }
        //cout<<temp->data;
    }
    cout<<endl;
}

void DeleteFront()
{

    Node *temp=head;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }

    if(temp->Rlink == NULL)
    {
        delete head;
        head=NULL;
        return;
    }

    head = head->Rlink;
    temp->Rlink = NULL;
    head->Llink = NULL;
    delete(temp);

}

void DeleteBack()
{
    Node *temp=head;
      if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    if(head->Rlink==NULL)
    {
        delete head;
        return;
    }
    Node *prev;

    while(temp->Rlink!=NULL)
    {
        temp=temp->Rlink;
    }
    prev = temp->Llink;
    prev->Rlink=temp->Rlink;
    temp->Llink=NULL;
    delete(temp);

}

void DeleteInBetween()
{
    int pos;
    cout<<"Enter the position : ";
    cin>>pos;
    Node *prev, *next;
    if(pos <1 || pos >Length())
    {
        cout<<"Invalid Position "<<endl;

    }
    else
    {
        Node *temp = head;
        pos--;
        while(pos--)
        {
            temp=temp->Rlink;
        }
        prev = temp->Llink;
        next  = temp->Rlink;
        next->Llink = temp->Llink;
        prev->Rlink = temp->Rlink;
        temp->Llink=NULL;
        temp->Rlink=NULL;
        delete(temp);
    }

}

int main()
{
    int choice;
    while(1)
    {
        cout<<"1.InsertFont"<<endl;
        cout<<"2.InsertBack"<<endl;
        cout<<"3.InsertInBetween"<<endl;
        cout<<"4.Length"<<endl;
        cout<<"5.Show"<<endl;

        cout<<"6.DeleteFront"<<endl;
        cout<<"7.DeleteBack"<<endl;
        cout<<"8.DeleteInBetween"<<endl;

        cout<<"Enter the choice :"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1 :// cout<<"Enter the value to insert : ";
                    // cin>>ele;
                     InsertFront();
                     break;

            case 2 : InsertBack();
                    break;

            case 3 :InsertAfter();
                    break;
            case 4 : len = Length();
                    cout<<"Length of a Linked List is : "<<len<<endl;
                    break;
            case 5 :show();

                    break;
            case 6: DeleteFront();
                    break;
            case 7:DeleteBack();
                    break;
            case 8:DeleteInBetween();
                    break;

            case 9: exit(1);
            default : cout<<"Invalid Input"<<endl;
        }
    }
}
