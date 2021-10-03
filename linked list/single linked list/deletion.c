#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node  * next;
};
void display(struct Node * ptr){
    for( ptr; ptr!=NULL;ptr=ptr->next){
        printf("Element: %d\n",ptr->data);
    } 
}
struct Node * deleteAtFirst(struct Node *head){
    struct Node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;

};
struct Node * deleteInBetween(struct Node *head,int index){
    struct Node *p=head;
    struct Node * q=head->next;
    int i=0;
    while(i!=index-1){
        q=q->next;
        p=p->next;
        i++;
    }
    p->next=q->next;

    free(q);
    return head;
}
struct Node * deleteAtEnd(struct Node *head){
    struct Node *ptr=head;
    struct Node *q=head->next;
    ptr=head;

    while(q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
void deleteAfterNode(struct Node *prev){
    struct Node *ptr=prev->next;
    prev->next=ptr->next;
    free(ptr);
    
}
int main(){
    struct Node * head=(struct Node *)malloc(sizeof(struct Node));
    struct Node * second=(struct Node *)malloc(sizeof(struct Node));
    struct Node * third=(struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth=(struct Node *)malloc(sizeof(struct Node));
    
    //Linking nodes
    head->data=10;
    head->next=second;

    second->data=15;
    second->next=third;
    
    third->data=20;
    third->next=fourth;
    
    fourth->data=30;
    fourth->next=NULL;
printf("before deletion:\n");
    display(head);
    
  //  head = deleteAtFirst(head);
    
 //   head=deleteInBetween(head,2);
   
  //  head=deleteAtEnd(head);
  
   deleteAfterNode(second);
    printf("\nafter deletion:\n");
     display(head);
    return 0;
}