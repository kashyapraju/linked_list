#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};

void traverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr!= NULL)
    {
        printf(" %d ", ptr->data);
     
        ptr = ptr->next;
    }
}

void insert_position(struct node *head, int item, int position)
{

    int count = 1;
    struct node *new, *t = head;
    new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("Overflow condition");
    }
    else
    {
        new->data = item;
        if (head == NULL)
        {
            head = new;
            head->next = NULL;
            head->prev = NULL;
        }

        else if (position == 1)
        {
            new->next = head;
            head->prev = new;
            new->prev = NULL;
            head = new;
        }

        while (count != (position - 1))
        {
            t = t->next;
            count++;
        }

        new->next = t->next;
        new->next->prev=new;
        t->next = new;
        new->prev = t;
    }
}

int main()
{
    struct node *head,*first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    head=first;
    first->data = 7;
    first->next = second;
    second->prev = first;
    first->prev = NULL;

    second->data = 8;
    second->next = third;
    third->prev = second;

    third->data = 3;
    third->next = fourth;
    fourth->prev = third;
   
    fourth->data = 7;
    fourth->next = fifth;
    fifth->prev = fourth;
   
    fifth->data = 2;
    fifth->next = NULL;

    traverse(head);
    printf("\n");
    insert_position(head, 1, 2);
    traverse(head);

    return 0;
}
