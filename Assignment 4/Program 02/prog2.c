// Write a C program to merge two already sorted list.  
// Mention the necessary algorithm.


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

node *merge_linked_list(node *head1, node *head2){
    node *head3 = NULL, *tail;
    //base case
    if(head1 ==NULL) return head2;
    if(head2 == NULL) return head1;

    //Initialize the pointer head3 with either of the first elements of the sorted linked list
    if(head1->data < head2->data){
        head3 = tail = head1;
        head1 = head1->next;
    }
    else{
        head3 = tail = head2;
        head2 = head2->next;
    }

    //General case
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            tail->next = head1;
            tail = head1;
            head1= head1->next;
        }
        else{
            tail->next = head2;
            tail = head2;
            head2= head2->next;
        }
    }

    //Adding the remianung part
    if(head1!= NULL)
        tail->next = head1;
    else{
        tail->next= head2;
    }
    return head3;
}

int main(){
    node *head1, *head2,*head3;
    printf("Enter the two sorted linked list:\n");
    head1 = createNode_at_last();
    head2 = createNode_at_last();
    head3 = merge_linked_list(head1,head2);
    display(head3);
    free_list(head1);
    free_list(head2);
    free_list(head3);
}