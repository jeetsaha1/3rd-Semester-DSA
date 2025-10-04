// Write a C program to create a Double Circular linked list along with the following functions:
//    a) to display the elements of a Double Circular Linked List.
//    b) to add an element at beginning of a Double Circular linked list.
//    c) to add an element at the end of a Double Circular linked list.
//    d) to add an element at any user given position of a Double Circular linked list.
//    e) to search a user given element in a Double Circular linked list.
//    f) to count the number of nodes in a Double Circular linked list.
//    g) to delete a node at beginning of a Double Circular linked list.
//    h) to delete a node at end of a Double Circular linked list.
//    i) to delete a node from any position of a Double Circular linked list.
//   (Create a menu bar using switch case statement in the main)


#include<stdio.h>
#include<stdlib.h>

//At first make a structure for Double linked list
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}node;

//Making the functions
node *createList(){
    node *head = NULL,*tail = NULL ,*nw;
    int data, ch =-1;
    while (ch!= 0){
        printf("Enter the data: ");
        scanf("%d",&data);

        nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;
        nw->prev = NULL;

        if (head == NULL){
            head = tail = nw;
            nw->next = head;
            nw->prev = head;
        }
               
        else{
            tail->next = nw;
            nw->prev = tail;
            tail = nw;
            tail->next = head;
            head->prev = tail;
        }

        printf("Do you want to insert(1/0): ");
        scanf("%d",&ch);
    }
    return head;
}

//a.To display element from linked list
void displayList(node *head){
    if(head == NULL){
        printf("Empty List");
        return ;
    }
    node *temp = head;
    while (temp->next!=head)
    {
        printf("%d -->",temp->data);
        temp = temp->next;
    }
    printf("%d-->NULL\n",temp->data);
}

//b.Add element at beginning
node *insert_at_begining(node *head,int val){
    node *nw = (node*)malloc(sizeof(node));
    nw->data = val;
    nw->prev = NULL;
    nw->next = NULL;

    if (head == NULL){
        head = nw;
        nw->prev = nw;
        nw->next = nw;
    }
    else{
        nw->next = head;
        nw->prev = head->prev;
        head->prev->next = nw;
        head->prev = nw;
        head = nw;
    }
    return head;
}

//c.Add element at ending
node *insert_at_end(node *head,int val){
    node *nw = (node*)malloc(sizeof(node));
    nw->data = val;
    nw->prev = NULL;
    nw->next = NULL;

    if (head == NULL){
        head = nw;
        nw->prev = nw;
        nw->next = nw;
    }   
    else{
        node *tail = head->prev;
        tail->next = nw;
        nw->prev = tail;
        nw->next = head;
        head->prev = nw;
    }
    return head;
}

//d.Add element at any position
node *insert_at_any(node *head,int val,int index){
    node *nw = (node*)malloc(sizeof(node));
    nw->data = val;
    nw->prev = NULL;
    nw->next = NULL;

    if (index ==0)
        return insert_at_begining(head,val);
    else{
        node *tail = head;
        int i = 0;
        while (tail->next != head && i<index-1){
            tail = tail->next;
            i++;
        }
        nw->next = tail->next;
        tail->next->prev = nw;
        tail->next = nw;
        nw->prev = tail;
    }
    return head;
}

//e.searching a user given element
int searching_element(node *head,int ele){
    int i=0;
    if (head == NULL){
        return -1;
    }
    node *temp = head;
    do{
        if(temp->data == ele)
            return i;
        i++;
        temp = temp->next;
    }while(temp->next != head);
    return -1;
}

//f.counting the node
int count_nodes(node *head){
    int count = 1;
    if (head == NULL){
        return 0;
    }
    else{
        node *temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
    }
    return count;
}

//g.deleting the node from the beginning
node *delete_at_begining(node *head){
    if (head == NULL) return NULL;
    if (head->next == head) {
    free(head);
    return NULL;
    }
    node *temp = head;
    head = head->next;
    head->prev = temp->prev;
    temp->prev->next = head;
    free(temp);
    return head;
}

//h.deleting the node from the ending
node *delete_at_end(node *head){
    if (head == NULL)
        return NULL;
    else{
        node *tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        free(tail);
    }
    return head;
}

//h.deleting the node from the any position
node *delete_at_any(node *head, int index){
    if (head == NULL)
        return NULL;
    if (index == 0)
        return delete_at_begining(head);
    node *tail = head;
    int i = 0;
    while (tail->next !=head && i<index)
    {
        tail = tail->next;
        i++;
    }
    tail->prev->next = tail->next;
    tail->next->prev = tail->prev;
    free(tail);
    return head;
}

int main(){
    node *head = NULL;
    int data,index,val, ch = -1;
    do{
        printf("___MENU___\nEnter the choice\n1.Create list\n2.Display List\n3.Insert at first\n4.Insert at last\n5.Insert at any\n6.Search element\n7.Count element\n8.Delete from first\n9.Delete from last\n10.Delete from any\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = createList();
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            printf("Enter the number : ");
            scanf("%d",&data);
            head = insert_at_begining(head,data);
            break;
        case 4:
            printf("Enter the number : ");
            scanf("%d",&data);
            head = insert_at_end(head,data);
            break;
        case 5:
            printf("Enter the number : ");
            scanf("%d",&data);
            printf("Enter the index number : ");
            scanf("%d",&index);
            head = insert_at_any(head,data,index);
            break;
        case 6:
            printf("Enter the  number for searching: ");
            scanf("%d",&val);
            int pos = searching_element(head,val);
            if (pos != -1) 
                printf("The element is found at node no. %d\n", pos);
            else 
                printf("Element not found\n");
            break;
        case 7:
            printf("The total no. of nodes: %d",count_nodes(head));
            break;
        case 8:
            head = delete_at_begining(head);
            break;
        case 9:
            head = delete_at_end(head);
            break;
        case 10:
            printf("Enter the index number: ");
            scanf("%d",&index);
            head = delete_at_any(head,index);
            break;
        case 11:
            printf("Exiting...");
            break;
        default:
            break;
        }
    }while(ch != 11);
    return 0;
}
