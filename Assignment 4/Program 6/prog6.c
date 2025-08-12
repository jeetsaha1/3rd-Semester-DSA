// Write a C program to detect a loop in a single linked list.

// Write a C program to reverse an already created single linked list.
// Mention the necessary algorithm.


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

//Main Problem
int detectloop(node *head){
    node *slow = head;
    node *fast = head;
    while (fast!= NULL && fast->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return 1;    
    }
    return 0;
}

node *reverseList(node *head){
    node *p = NULL,*q = head, *r = head->next;
    while(r!= NULL){
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    head = q;
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

int main(){
     node *head;
    int ch,index;
    do{
        printf("____MENU____\nEnter your choice\n1.Insert at first\n2.Insert at last\n3.Insert at index\n4.Delete at first\n5.Delete at last\n6.Delete at index\n7.Reverse List\n8.Detect loop\n9.Exit\n\n");
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
                head = reverseList(head);
                display(head);
                break;
            case 8:
                printf("%d",detectloop(head));
            case 9:
                printf("Exiting...");
                break;
            default:
                printf("You give wrong input");
                break;
        }
    }while(ch != 9);

    free_list(head);
    return 0;
}