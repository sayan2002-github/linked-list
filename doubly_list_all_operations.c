#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} nod;
nod *tail, *newnode;

int getLength()
{
    nod *temp;
    int count = 0;
    temp = tail->next;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    count++;
    return count;
}

// display fuction
void display()
{
    nod *temp;
    temp = tail->next;
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    printf("%d\n", temp->next->data);
}

// Insertion operations
void insertion_at_beg(){
    newnode = (nod *)malloc(sizeof(nod));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = tail->next;
    tail->next = newnode;
}

void insertion_at_end(){
    newnode = (nod *)malloc(sizeof(nod));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

void insertion_at_pos(){
    int i = 1, pos, size;
    nod *temp;
    temp = tail->next;
    size = getLength();
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>size+1){
        printf("Inavlid position\n");
    }
    else if(pos == 1){
        insertion_at_beg();
    }
    else if(pos == size+1){
        insertion_at_end();
    }
    else{
        newnode = (nod *)malloc(sizeof(nod));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertion()
{
    int choice = 1;
    printf("Inertion\n1 for at beginning\n2 for at end\n3 for at position\n4 for display\n5 for exit\n");
    while (choice != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Insertion at beginning\n");
            insertion_at_beg();
            break;
        case 2:
            printf("Insertion at end\n");
            insertion_at_end();
            break;
        case 3:
            printf("Insertion at position\n");
            insertion_at_pos();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}

// Deletion operations
void deletion_at_beg(){
    nod *temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
}

void deletion_at_end(){
    nod *temp, *Node;
    int i = 1, size = getLength();
    temp = tail->next;
    while(i<size){
        temp = temp->next;
        i++;
    }
    temp->next = tail->next;
    Node = tail;
    tail = temp;
    free(Node);
}

void deletion_at_pos(){
    int i = 1, pos, size;
    nod *temp, *Node;
    temp = tail->next;
    size = getLength();
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>size){
        printf("Inavlid position\n");
    }
    else if(pos == 1){
        deletion_at_beg();
    }
    else if(pos == size){
        deletion_at_end();
    }
    else{
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        Node = temp->next;
        temp->next = Node->next;
        free(Node);
    }
}

void deletion(){
    int choice = 1;
    printf("Deletion\n1 for at beginning\n2 for at end\n3 for at position\n4 for display\n5 for exit\n");
    while (choice != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Deletion at beginning\n");
            deletion_at_beg();
            break;
        case 2:
            printf("Deletion at end\n");
            deletion_at_end();
            break;
        case 3:
            printf("Deletion at position\n");
            deletion_at_pos();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}

// Reversal operation
void reversal(){
    nod *prev, *current, *nextnode;
    current = tail->next;
    nextnode = current->next;
    while(current != tail){
        prev = current;
        current = nextnode;
        nextnode = current->next;
        current->next = prev;
    }
    nextnode->next = tail;
    tail = nextnode;
}

// Main driver code
int main()
{
    nod *head;
    int choice = 1;
    tail = 0;
    while (choice)
    {
        newnode = (nod *)malloc(sizeof(nod));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (tail == 0)
        {
            tail = head = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        tail->next = head;

        printf("Do you want to continue?: ");
        scanf("%d", &choice);
    }
    display();

    // Menu driven program
    printf("Enter\n1 for insertion\n2 for deletion\n3 for reversal\n4 for display\n5 for exit\n");
    while (choice != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Insertion\n");
            insertion();
            break;
        case 2:
            printf("Deletion\n");
            deletion();
            break;
        case 3:
            printf("Reversal\n");
            reversal();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}