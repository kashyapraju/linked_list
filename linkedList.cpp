
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int val) // make a constructor which has two values
	{
		data = val;
		next = NULL;
	}
};

void makeCycle(node *&head, int pos) // make a cycle in any linked list by this function pos is that position from where loop will start.
{
	node *temp = head;
	node *startNode;

	int count = 1;
	while (temp->next != NULL)
	{
		if (count == pos)
		{
			startNode = temp;
		}
		temp = temp->next;
		count++;
	}

	temp->next = startNode;
}

bool detectCycle(node *&head) // this function detect that our linked list has cycle or not.
{
	node *slow = head;
	node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
		{
			return true;
		}

		return false;
	}
}

void remove(node *&head)
{

	node *slow = head;
	node *fast = head;

	do
	{
		slow = slow->next;
		fast = fast->next->next;

	} while (slow != fast);

	fast = head;
	while (slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = NULL;
}

void reverse(node *&head)
{
	node *pre = NULL;
	node *current = head;
	node *nex;

 while(current!=NULL)
	{
	    nex=current->next;
	    current->next=pre;
	    
	    pre=current;
	    current=nex;
	    
	    
	}

	return pre;
}

node* reversek(node* &head, int k)// if we want reverse k nodes together
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    
    int count = 0;
    
    while(currptr!NULL && count<k)// firstly we reverse k nodes 
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    
    if(nextptr!NULL)
    {
        head->next=reversek(nextptr,k);//now point the node which is frount of k node to the head means 1 node in case of k = 2
      
    }
    return prevptr;
}

void deletHead(node *&head)
{
	node *todelete = head;
	head = head->next;
	delete todelete;
}

void delet(node *&head, int val)
{

	// if (head == NULL)// if head contain null value
	// {
	// 	return;
	// }
	// if (head->next = NULL)// if we want delet a node but list contains only one node
	// {
	// 	deletHead(head);
	// 	return;
	// }
	node *temp = head;
	while (temp->next->data != val)
	{
		temp = temp->next;
	}

	node *todelet = temp->next;
	temp->next = temp->next->next;

	delete todelet;
}

void insertAttail(node *&head, int value) // insert a node at position end
{
	node *n = new node(value);
	if (head == NULL) // if head does not has any value
	{
		head = n;
		return;
	}

	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = n;
	// n->next=NULL;
}

void display(node *head) // display all the elements of the linked list
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	node *head = NULL;
	insertAttail(head, 1);
	insertAttail(head, 2);
	insertAttail(head, 3);
	insertAttail(head, 4);
	insertAttail(head, 5);
	insertAttail(head, 6);
	display(head);
	
         int k = 2;
	
	node* newhead= reversek(head,k);
	display(newhead);
	
	// delet(head, 8);
	// display(head);
	// deletHead(head);
	// display(head);
	makeCycle(head,3);
	cout<<detectCycle(head)<<endl;
	remove(head);
	cout<<detectCycle(head)<<endl;
	display(head);


	return 0;
}
