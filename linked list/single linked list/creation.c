#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node  * next;
};
void display(struct Node * ptr){
    struct Node *tmp=ptr;
    printf("%d\n",ptr->data);
    tmp=ptr->next;
    for( tmp; tmp->next!=ptr->next;tmp=tmp->next){
        printf("Element: %d\n",tmp->data);
    }
    
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
    fourth->next=head;
    
    display(head);
    return 0;
}