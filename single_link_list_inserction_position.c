// link list inserction at position
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *inserction_position(struct node *head, int item, int position)
{
    int count = 1;
    struct node *t, *t1 = head;
    if (t == NULL)
    {
        printf("overflow condition");
    }
    else
    {
        t->data = item;
        if (position == 1)
        {
            t->next = head;
            head = t;
        }
        else
        {
            while (count != (position - 1))
            {
                t1 = t1->next;
                count++;
            }
            t->next = t1->next;
            t1->next = t1;
            return 0;
        }
    }
}

void lkd(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head = first;
    first->data = 6;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    lkd(head);
   head= inserction_position(first, 1,1);
    lkd(head);

    return 0;
}
