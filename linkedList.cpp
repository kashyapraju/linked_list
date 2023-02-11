
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
	insertAttail(head, 6);
	insertAttail(head, 8);
	insertAttail(head, 3);
	display(head);
	delet(head, 8);
	display(head);
	// deletHead(head);
	// display(head);

	return 0;
}
