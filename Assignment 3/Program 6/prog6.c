// Write a program to print the odd number and even number nodes separately from a
// single linked list.


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

node *createNode_at_first(){
    node *nw, *head = NULL;
    int ch = 1,data;
    while (ch!=0)
    {
        printf("Enter the data: ");
        scanf("%d",&data);

        nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->next = head;
        head = nw;

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

node *createNode_at_last(node *head){
    node *nw, *p;
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

node *deleteNode_at_last(node *head){
    if (head == NULL){
        printf("Empty list");
        return NULL;
    }
    else if(head->next == NULL){
        free(head);
    }
    else{
        node *p =head;
        node *q = p->next;
        while (q->next!= NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
}
    return head;
}

node *createNode_at_index(node *head, int index){
    node *nw, *p;
    int ch = 1,i=0,data;
    while (ch!=0)
    {
        printf("Enter the data: ");
        scanf("%d",&data);

        nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;
        
        if (index == 0){
            nw->next = head;
            head = nw;
            return head;
        }
        else{
            p = head;
            while (p!=NULL && i < index-1)
            {
                p = p->next;
                i++;
            }
            nw->next = p->next;
            p->next = nw;
        }

        printf("Do you want to input:");
        scanf("%d",&ch);
    }
    return head;
}

node *deleteNode_at_index(node *head,int index){
     if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    else{
        node *p = head;
        int i = 0;
        if(index == 0){
            node *temp = head;
            head = head->next;
            free(temp);
            return head;
        }
        while(p != NULL && i<index-1){
            p = p->next;
            i++;
        }
        node *q = p->next;
        p->next = q->next;
        free(q);
    }
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

void print_even_odd(node *head){
    if(head == NULL){
        printf("Empty list");
        return ;
    }
    else{
        node *p = head;
        while (p!= NULL){
            if(p->data%2 == 0){
                printf("Even : %d -->",p->data);
            }
            p = p->next;
        }
        printf("NULL");
        printf("\n");
        node *q = head;
        while (q!= NULL){
            if(q->data%2 != 0){
                printf("Odd : %d -->",q->data);
            }
            q = q->next;
        }
        printf("NULL");
    }
}

int main(){
     node *head;
    int ch,index;
    do{
        printf("\n____MENU____\nEnter your choice\n1.Insert at first\n2.Insert at last\n3.Insert at index\n4.Delete at first\n5.Delete at last\n6.Delete at index\n7.Print even odd seperately\n8.Exit\n\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                head = createNode_at_first();
                display(head);
                break;
            case 2:
                head = createNode_at_last(head);
                display(head);
                break;
            case 3:
                printf("Enter the index no.: ");
                scanf("%d",&index);
                head = createNode_at_index(head,index);
                display(head);
                break;
            case 4:
                head = deleteNode_at_first(head);
                display(head);
                break;
            case 5:
                head = deleteNode_at_last(head);
                display(head);
                break;
            case 6:
                printf("Enter the index no.: ");
                scanf("%d",&index);
                head = deleteNode_at_index(head,index);
                display(head);
                break;

            case 7:
                print_even_odd(head);
                break;
            case 8:
                printf("Exiting...");
                break;
            default:
                printf("You give wrong input");
                break;
        }
    }while(ch != 8);

    free_list(head);
    return 0;
}