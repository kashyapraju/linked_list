#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

void traverse(struct node *head)
{
    struct node *t = head;
    if (t == NULL)
    {
        printf("Empty linked list ");
    }

    else
    {
        do
        {

            printf("%d", t->data);
            t = t->next;
        } while (t != head);
    }
}

void inserct_position(struct node *head, int item, int position)
{
    int count = 1;
    struct node *new, *t = head;

    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("overflow condition ");
    }
    else
    {
        new->data = item;
        if (head == NULL)
        {
            head = new;
            head->next = head;
        }

        else if (position == 1)
        {
            while (t->next != head)
            {
                t = t->next;
            }

            new->next = head;
            head = new;
            t->next = head;
        }
        else
        {
            while (count != (position - 1))
            {
                t = t->next;
                count++;
            }

            new->next = t->next;
            t->next = new;
        }
    }
}

int main()
{
    struct node *head, *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head = first;
    first->data = 4;
    head->next = second;
    second->data = 7;
    second->next = third;
    third->data = 9;
    third->next = fourth;
    fourth->data = 3;

    fourth->next = fifth;
    fifth->data = 1;
    fifth->next = head;

    traverse(head);
    printf("\n");

    inserct_position(head, 2, 3);

    traverse(head);

    return 0;
}