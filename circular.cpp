#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAthead(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;

    head = n;
}

void insertAttail(node *&head, int value)

{

    if (head == NULL)
    {
        insertAthead(head, value);
        {
            return;
        }
    }
    node *n = new node(value);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void display(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteAthead(node* &head)
{
    node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    node* todelete = head;
    temp->next-head->next;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int pos)
{
    if(pos==1)
    {
        deleteAthead(head);
        return;
    }
    node* temp = head;
    int count = 1;

    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next=temp->next->next;// last node connect with first node
   delete todelete;
}

int main()
{

    node *head = NULL;
    insertAttail(head, 1);
    insertAttail(head, 3);
    insertAttail(head, 6);
    insertAttail(head, 8);
    insertAttail(head, 9);

    display(head);
    insertAthead(head,2);
    
    display(head);

    deletion(head,5);
    display(head);




    return 0;
}
