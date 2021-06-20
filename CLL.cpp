//circular linked list

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
};

int len = 0;

Node *head = NULL;

void InsertFront()
{
    int ele;
    cout<<"Enter the element : ";
    cin>>ele;
    Node *new_node = new Node();
    new_node->data = ele;
    new_node->link = new_node;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;
        while(current->link!=head)
        {
            current=current->link;
        }
        new_node->link = head;
        current->link = new_node;
        head = new_node;

    }
}

void InsertBack()
{
    int ele;
    Node *new_node = new Node();
    cout<<"Enter the element : ";
    cin>>ele;
    new_node->data = ele;
    new_node->link = new_node;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *tail= head;
        while(tail->link!=head)
        {
            tail = tail->link;
        }
        new_node->link = head;
        tail->link = new_node;



    }
}

int Length()
{
    int Count=0;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return 0;
    }
    else
    {
        Node *current=head;
        /*while(current->link!=head)
        {
            current = current->link;
            Count++;
        }*/
        do{
            current = current->link;
            Count++;
        }while(current!=head);
        return Count;
    }
}

void show()
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
        return;
    }
    else
    {
        Node *current = head;
        while(current->link!=head)
        {
            cout<<current->data<<" ";
            current=current->link;
        }
        cout<<current->data<<endl;

    }
}

void DeleteFront()
{
    Node *temp=head;
    Node *tail =head;
    if(head==NULL)
    {
        cout<<"List is Empty :"<<endl;
        return;
    }
   if(tail->link==tail)
    {
        //delete(tail);
        head = NULL;
        return;
    }
    while(tail->link!=head)
    {
        tail = tail->link;
    }
   tail->link=head->link;

   head = head->link;
   //temp->link=temp;
   delete(temp);
}

void DeleteBack()
{
    Node *temp = head;
    Node *prev = head;
    if(head->link == NULL)
    {
        cout<<"List is Empty "<<endl;
            return;
    }
    else if(temp->link==temp)
    {
        delete(temp);
        return;
    }

    while(temp->link!=head)
    {
        temp=temp->link;
    }

    while(prev->link!=temp)
    {
        prev = prev->link;
    }
    prev->link = head;
    //temp->link = temp;
    delete(temp);


}


int main()
{
    int choice;

    while(1)
    {
        cout<<"*************************"<<endl;
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
/*
            case 3 :InsertAfter();
                    break; */
            case 4 : len = Length();
                    cout<<"Length of a Linked List is : "<<len<<endl;
                    break;

            case 5 :show();
                    break;

            case 6: DeleteFront();
                    break;

            case 7:DeleteBack();
                    break;
                     /*
            case 8:DeleteInBetween();
                    break;
    */
            case 9: exit(1);
            default : cout<<"Invalid Input"<<endl;
        }
    }
}
