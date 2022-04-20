#include<stdio.h>
#include<stdlib.h>
 struct node 
 { 
     int data;
     struct node *next;
 };  
 void lkd(struct node *head)
     {
         struct node *ptr=head;
         while(ptr!=NULL)
         {
             printf("%d",ptr->data);
             ptr=ptr->next;
         }
         
     } 
    struct node *delet_starting(struct node *head)
    { 
        struct node *t;
        if(head==NULL)

        { 
            printf("UNDERFLOW ERROR");
        }
         else 
         {   t=head;
             head=head->next;
             free(t);
             return head;
         }                    

    }
   int main()
  {
      struct node *head;
      struct node *first;
      struct node *second;
      struct node *third;
      first=(struct node*)malloc(sizeof(struct node));
      second=(struct node*)malloc(sizeof(struct node));
      third=(struct node*)malloc(sizeof(struct node));
      head=first;

      first->data=1;
      first->next=second;
       
         second->data=2;
       second->next=third;
        
        third->data=3;
        third->next=NULL;

        lkd(head);
         
       head = delet_starting(head);
       printf("\n");
        lkd(head);

        return 0;
  }
       

