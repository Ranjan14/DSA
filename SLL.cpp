#include<bits/stdc++.h>
using namespace std;
int Length();


class Node{
public:
    int data;
    Node *link;
};

Node *head = NULL; //root
int len;//=Length();

void InsertFront()
{
    int ele;
    Node *new_node = new Node();
    cout<<"Enter the element : ";
    cin>>ele;
    new_node->data = ele;
    new_node->link=head;
    head=new_node;
}

void InsertBack()  //pushback / append
{
    int ele;
    Node *new_node = new Node();

    cout<<"Enter the element : ";
    cin>>ele;
    new_node->data=ele;
    new_node->link = NULL;
    Node *prev = head;
    if(head==NULL)
    {
        head=new_node;
        return;
    }

    while(prev->link!=NULL)
    {
        prev=prev->link;
    }
    prev->link=new_node;

}

void InsertAfter()
{
    int ele,pos;
    Node *new_node = new Node();
    cout<<"Enter the element" <<endl;
    cin>>ele;
    cout<<"Enter the position"<<endl;
    cin>>pos;
    if(pos<1 || pos>Length())
    {
        cout<<"Invalid "<<endl;
    }
    else
    {
        pos--;
        Node *prev;//*next;
        prev=head;
        //next=head;
        //next=next->link;
        while(pos)
        {

            //next=next->link;
            pos--;
            if(pos==0)
            {
                new_node->data=ele;
                new_node->link=prev->link;
                prev->link=new_node;

                //new_node->link=next;
            }
            prev=prev->link;
        }
    }
}

int Length()
{
    int Count=0;
    Node *temp=new Node();
    temp=head;
    if(temp==NULL)
    {
        cout<<"Empty"<<endl;
        return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            temp=temp->link;
            Count++;
        }
        return Count;
    }
}

void show()
{
    Node *temp = new Node();
    temp=head;
    if(temp==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
        cout<<endl;
    }
}


void DeleteFront()
{
    Node *temp;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    if(head->link==NULL)
    {
        delete head;
        return;
    }

    temp=head;
    head=temp->link;
    temp->link=NULL;
    delete (temp);
}

void DeleteBack()
{
    Node *temp;
     if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    if(head->link==NULL)
    {
        delete head;
        return;
    }
    temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    Node *prev=head;
    while(prev->link!=temp)
    {
        prev=prev->link;
    }
    prev->link=temp->link;
    delete(temp);
}

void DeleteInBetween()
{
    int pos;
    cout<<"Enter the position : "<<endl;
    cin>>pos;
    pos=pos-2;
    Node *prev, *temp;
    prev = head;
    while(pos--)
    {
        prev=prev->link;
    }
    temp = prev->link;
    prev->link=temp->link;
    temp->link=NULL;
    delete(temp);

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
            default : cout<<"Invalid Input"<<endl;
        }
    }
}
