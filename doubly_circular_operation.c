#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} nod;
nod *head, *tail, *newnode;

int getLength()
{
    int count = 0;
    nod *temp;
    temp = head;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    count++;

    return count;
}

// Display functions
void display()
{
    nod *temp;
    temp = head;
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    printf("%d\n", temp->next->data);
}

// Insertion functions
void insertion_at_beg()
{
    newnode = (nod *)malloc(sizeof(nod));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
    tail->next = newnode;
    head = newnode;
}

void insertion_at_end()
{
    newnode = (nod *)malloc(sizeof(nod));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
    tail->next = newnode;
    tail = newnode;
}

void insertion_at_pos()
{
    int i = 1, pos, size;
    nod *temp;
    size = getLength();
    temp = head;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1)
    {
        printf("Invalid position\n");
    }
    else if (pos == 1)
    {
        insertion_at_beg();
    }
    else if (pos == size + 1)
    {
        insertion_at_end();
    }
    else
    {
        newnode = (nod *)malloc(sizeof(nod));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void insertion()
{
    int choice = 1;
    printf("Insertion\n1 for at  beginning\n2 at end\n3 for at position\n4 for display\n5 for exit\n");
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

// Deletion opertions
void deletion_from_beg(){
    nod *temp;
    temp = head;
    tail->next = head->next;
    head->next->prev = tail;
    head = head->next;
    free(temp);
}

void deletion_from_end(){
    nod *temp;
    temp = tail;
    tail->prev->next = head;
    head->prev = tail->prev;
    tail = tail->prev;
    free(temp);
}

void deletion_from_pos(){
    nod *temp;
    int i = 1, pos, size;
    size = getLength();
    temp = head;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>size){
        printf("Invalid position\n");
    }
    else if(pos == 1){
        deletion_from_beg();
    }
    else if(pos == size){
        deletion_from_end();
    }
    else{
        while(i<pos){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void deletion(){
    int choice = 1;
    printf("Deletion\n1 for at  beginning\n2 at end\n3 for at position\n4 for display\n5 for exit\n");
    while (choice != 5)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Deletion at beginning\n");
            deletion_from_beg();
            break;
        case 2:
            printf("Deletion at end\n");
            deletion_from_end();
            break;
        case 3:
            printf("Deletion at position\n");
            deletion_from_pos();
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

int main()
{
    int choice = 1;
    head = tail = NULL;
    while (choice)
    {
        newnode = (nod *)malloc(sizeof(nod));
        printf("\nEnter the data: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
        }
        newnode->next = head;
        head->prev = newnode;

        printf("Do you want to continue?: ");
        scanf("%d", &choice);
    }
    // Menu driven program
    printf("Enter\n1 for insertion\n2 for deletion\n3 for display\n4 for exit\n");
    while (choice != 4)
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
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}