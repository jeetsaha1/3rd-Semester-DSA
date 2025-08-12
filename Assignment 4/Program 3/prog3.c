// Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

node *createNode_at_last(){
    node *nw, *p, *head = NULL;
    int ch = 1,data;
    while (ch!=0)
    {
        printf("Enter the data: ");
        scanf("%d",&data);

        nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;
        if (head == NULL)
            head = nw;
        else{
            p = head;
            while (p->next!= NULL)
                p = p->next;
            p->next = nw;
            nw->next = NULL;
        }

        printf("Do you want to input:");
        scanf("%d",&ch);
    }
    return head;
}

node *deleteNode_at_first(node *head){
    node *p =head;
    head = head->next;
    free(p);
    return head;
}

void free_list(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void display(node *head){
    node *temp = head;
    while(temp!= NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node *left_shift(node *head, int k){
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    node *temp = head,*head1;
    int i = 1;
    while (temp != NULL && i< k){
        temp = temp->next;
        i++;
    } 
    if (temp == NULL || temp->next == NULL)
        return head; 

    head1 = temp->next;
    temp->next = NULL;

    node *p =head1;
    while(p->next!= NULL){
        p = p->next;
    }
    p->next = head;

    return head1;

}

int main(){
    node *head;
    head = createNode_at_last();
    display(head);
    int k;
    printf("Enter the node no.:");
    scanf("%d",&k);
    head = left_shift(head,k);
    display(head);
    free_list(head);
    return 0;
}