#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void lnk(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)

    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

void deletion_at_position(int position, struct Node *head)
{
    int count = 1;
    struct Node *t, *t1 = head;
    if (head == NULL)
    {
        printf("under flow");
    }
    else
    {
        if (position == 1)
        {
            t = head;
           head= head->next;
            free(t);
        }
        else
        {
            while (count!= (position - 1))
            {
                t1=t1->next;
                count++;
            }
            t = t1->next;
            t1->next = t1->next->next;
            free(t);
           // return head;
        }
    }
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head = first;
    first->data = 3;
    first->next = second;

    second->data = 5;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = NULL;

    lnk(head);
    deletion_at_position(3,head);
    lnk(head);
    return 0;
}