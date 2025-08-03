// Write a C program to implement the following functions for single linked list.
// • createList
// • insertAtFirst
// • insertAtLast
// • insertAtAny
// • displayList .
// Mention the necessary algorithm.(Uncomplete)

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

//Algorithm of createNode_at_first
// createNode_at_first()
// BEGIN
//     Initialize the node pointer nw and head  <- NULL
//     Initialize the variable data and ch <- 1
//     WHILE ch != 0 DO
//         Set nw.data ← data
//         Set nw.next ← head
//         Set head ← nw
//         Prompt user to continue (1) or stop (0)
//     END WHILE
// END

node *deleteNode_at_first(node *head){
    node *p =head;
    head = head->next;
    free(p);
    return head;
}

//Algorithm of deleteNode_at_first()
// deleteNode_at_first(head)
// BEGIN
//     intitalize the pointer node p <- head;
//     head <- head.next
//     free the node p
//     RETURN head
// END

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

//Algorithm of createNode_at_last
// createNode_at_last(head)
// BEGIN
//     Initialize the node pointer nw and p
//     Initialize the variable data and ch <- 1
//     WHILE ch != 0 DO
//         Set nw.data ← data
//         Set nw.next ← head
//         Set head ← NULL
        
//         IF head == NULL THEN
//             head <- nw;
//         ELSE
//             p <- head
//             WHILE p.next != NULL DO
//                 p <- p.next
//             END WHILE
//             p.next <- nw;
//             nw.next <- NULL
//         END IF
//         Prompt user to continue (1) or stop (0)
//     END WHILE
//     RETURN HEAD
// END

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

//Algorithm of deleteNode_at_last()
// deleteNode_at_last(head)
// BEGIN
//      IF head == NULL THEN
//          print "Empty List"
//          RETURN NULL
//      ELSE IF head.next != NULL
//          free the head
//      ELSE
//          initialize the node p <- head and q <- p.next
//          WHILE q.next != NULL DO
//              p <- p.next
//              q <- q.next
//          END WHILE
//          p.next <- NULL
//          free the node q
//      END IF
//      RETURN head

// END

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

//Algorithm of createNode_at_index
// createNode_at_index(head,index)
// BEGIN
//     Initialize the node pointer nw and p
//     Initialize the variable data ,ch <- 1 ,i = 0
//     WHILE ch != 0 DO
//         Set nw.data ← data
//         Set nw.next ← head
//         Set head ← NULL
        
//         IF head == NULL THEN
//             head <- nw;
//         ELSE
//             p <- head
//             WHILE p.next != NULL and i<= index-1 DO
//                 p <- p.next
//                 i <- i+1
//             END WHILE
//             nw.next <- p.next
//             p.next <- nw
//         END IF
//         Prompt user to continue (1) or stop (0)
//     END WHILE
//     RETURN HEAD
// END

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

//Algorithm of deleteNode_at_index()
// deleteNode_at_index(head,index)
// BEGIN
//      IF head == NULL THEN
//          print "Empty List"
//          RETURN NULL 
//      ELSE
//          initialize the node p <- head and variable i = 0
//          IF index== 0 THEN
//              Initialize the node temp <- head
//              head <- head.next
//              free the node temp
//              RETURN head
//          END IF

//          WHILE q.next != NULL and i< index-1 DO
//              p <- p.next
//              i <- i+1
//          END WHILE
//          Initialize the node q <- p.next
//          p.next = q.next
//          free the node q
//      END IF
//      RETURN head

// END

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

//Algorithm for display()
// display(head)
// BEGIN
//     Initialize the node temp <- head
//     WHILE temp != NULL DO
//         print"temp.data"
//         temp <- temp.next
//     END WHILE
//     print"NULL"
// END

int main(){
     node *head;
    int ch,index;
    do{
        printf("____MENU____\nEnter your choice\n1.Insert at first\n2.Insert at last\n3.Insert at index\n4.Delete at first\n5.Delete at last\n6.Delete at index\n7.Exit\n\n");
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
                printf("Exiting...");
                break;
            default:
                printf("You give wrong input");
                break;
        }
    }while(ch != 7);

    free_list(head);
    return 0;
}