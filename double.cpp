#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void delethead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletion(node* &head, inr pos)
{
    if(pos==1)
    {
        delethead(head);
        return;
    }
    
    node* temp=head;
    int count = 1;

    while(temp!=NULL && count!=pos)
        {

           temp=temp->next;
            count++;
        }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    {
    temp->next->prev=temp->prev;   
    }

    delet temp;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtTail(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    display(head);
    insertAtTail(head, 5);
    display(head);
    deletion(head,5);
     display(head);
    

    return 0;
}
