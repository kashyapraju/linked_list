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

void deletion_position(struct node *head,int position)
{
    int count=1;
    struct node *t1=head,*t;
    if(head==NULL)
    {
        printf("underflow condition ");
    }

    else{
        if(head->next==NULL)
        {
        free(head);
        head=NULL;
        }

        else if (position==1)
        {
            t=head;
            head=head->next;
            free(t);
            head->prev=NULL;
        }
         
         else{
             while (count!=(position-1))
             {
                 t1=t1->next;
                 count++;
             }

             t=t1->next;
             t1->next=t->next;
             t->next->prev=t1;


             free(t);

             
         }
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
    deletion_position(head,3);
    traverse(head);
   



    return 0;
}