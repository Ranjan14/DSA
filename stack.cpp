#include<bits/stdc++.h>
using namespace std;
#define size 5

int stack1[size];
int top=-1;
int isFull();
int isEmpty();


void push(int ele)
{
    if(isFull())
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        top++;
        stack1[top]=ele;

    }
}

int isFull()
{
    if(top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        int a=stack1[top];
        cout<<a<<" is poped out"<<endl;
        top--;
    }
}

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traverse()
{
    for(int i=top;i>=0;i--)
    {
        cout<<stack1[i]<<endl;
    }
    cout<<endl;
}

int main()
{
    int choice,ele;
    while(1)
    {
        cout<<"Enter the choice"<<endl<<"1.push"<<endl<<"2.pop"<<endl<<"3.Traverse"<<endl<<"4.peek"<<endl<<"5.quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the element: ";
                    cin>>ele;
                    push(ele);
                    break;
            case 2: pop();
                    break;
            case 3: cout<<"The elements in the stack are :"<<endl;
                    traverse();
                    break;
            case 4: cout<<"peek element is :"<<stack1[top]<<endl;
                    break;
            case 5: exit(0);
            default : cout<<"Invalid choice"<<endl;
        }
    }
return 0;
}
