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
   void insert_position( struct node *head,int item,int position)
{
int count=1;
struct node *t1=head,*new;
new=(struct node *)malloc(sizeof(struct node));
if(new==NULL)
{
printf("Overflow Condition");
}
else
{
new->data=item;
if(position==1)
{
if(head==NULL) // no node in linked list
{
head=new;
head->next=head;
}
else
{

while(t1->next!=head)
{
t1=t1->next;
}
new->next=head;
head=new;
t1->next=new;
}
}
else{
while(count!=(position-1))
{
t1=t1->next;
count++;
}
new->next=t1->next;
t1->next=new;
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

   insert_position(head,2,3);

    traverse(head);

    return 0;
}