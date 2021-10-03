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
struct Node * insertionAtFirst(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;

};
struct Node * insertInBetween(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next = ptr;
    return head;
}
struct Node * insertAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;
    return head;
}
void insertAfterNode(struct Node *prev,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=prev->next;
    prev->next=ptr;
    ptr->data=data;
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
printf("before insertion:\n");
    display(head);
    
   // head = insertionAtFirst(head,52);
    
   // head=insertInBetween(head,89,3);
   
   // head=insertAtEnd(head,99);
   insertAfterNode(third,78);
    printf("\nafter insertion:\n");
     display(head);
    return 0;
}