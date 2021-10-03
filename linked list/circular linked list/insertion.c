#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node  * next;
};
void display(struct Node * ptr){
    struct Node *tmp;
    printf("Element: %d\n",ptr->data);
    tmp=ptr->next;
    for( tmp; tmp!=ptr;tmp=tmp->next){
        printf("Element: %d\n",tmp->data);
}
}
struct Node * create(struct Node * head,int n){
    struct Node * tmp=head;
    int num;
  
    for (int i=2;i<=n;i++){
        struct Node * ptr=malloc(sizeof(struct Node));
        printf("enter the data for node %d:",i);
        scanf("%d",&num);
        ptr->data=num;
        ptr->next=NULL;
        tmp->next=ptr;
        tmp=ptr;
        
    }
    tmp->next=head;
    return head;
}
struct Node * insertAtBeginning(struct Node *head,int value){
    struct Node * ptr= malloc(sizeof(struct Node));
    struct Node *temp=head;
    for(temp;temp->next!=head;temp=temp->next);
    ptr->data=value;
    temp->next = ptr;
    ptr->next = head;

   head=ptr;
   return head;
}
int main(){
    struct Node * head=malloc(sizeof(struct Node));
    int n;
    printf("enter the no. of elements in linked list:");
    scanf("%d",&n);
    printf("enter the data for node 1:");
    scanf("%d",&(head->data));
    head->next=NULL;
    head=create(head,n);
    printf("befor insertion:\n");
    display(head);
    
    printf("\nafter insertion:\n");
    head=insertAtBeginning(head,54);
     display(head);
    return 0;
}