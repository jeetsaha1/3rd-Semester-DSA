// Write a C program to merge two already sorted double list. 

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

        if (head == NULL)
            head = tail = nw;   
        else{
            tail->next = nw;
            nw->prev = tail;
            tail = nw;
            nw->next = NULL;
        }

        printf("Do you want to insert(1/0): ");
        scanf("%d",&ch);
    }
    return head;
}

//a.To display element from linked list
void displayList(node *head){
    node *temp = head;
    while (temp->next!=NULL)
    {
        printf("%d -->",temp->data);
        temp = temp->next;
    }
    printf("%d-->NULL\n",temp->data);
}

node *merge_list(node *head1, node *head2){
    if (head1 == NULL)  return head2;
    if (head2 == NULL)  return head1;

    node *head3 = NULL,*tail = head3;
    while (head1!= NULL && head2 != NULL)
    {
        if(head1->data <= head2->data){
            if (head3 == NULL){
                head3 = head1;
                tail = head1;
            }
            else{
                tail->next = head1;
                head1->prev = tail;
                tail = head1;
            }
            head1 = head1->next;
            
        }
        else{
            if (head3 == NULL){
                head3 = head2;
                tail = head2;
            }
            else{
                tail->next = head2;
                head2->prev = tail;
                tail = head2;
            }
            head2 = head2->next;
        }
    }

    while(head1!= NULL){
        tail->next = head1;
        head1->prev = tail;
        tail = head1;
        head1= head1->next;
    }
    
    while (head2 != NULL)
    {
        tail->next = head2;
        head2->prev = tail;
        tail = head2;
        head2 = head2->next;
    }
    return head3;
}

int main(){
    node *head1,*head2,*head3;
    head1 = createList();
    displayList(head1);
    head2 = createList();
    displayList(head2);
    head3 = merge_list(head1,head2);
    displayList(head3);
    return 0;
}


// Enter the data: 1
// Do you want to insert(1/0): 1
// Enter the data: 3
// Do you want to insert(1/0): 3
// Enter the data: 5
// Do you want to insert(1/0): 0
// 1 -->3 -->5-->NULL
// Enter the data: 2
// Do you want to insert(1/0): 2
// Enter the data: 4
// Do you want to insert(1/0): 4
// Enter the data: 6
// Do you want to insert(1/0): 0
// 2 -->4 -->6-->NULL
// 1 -->2 -->3 -->4 -->5 -->6-->NULL
