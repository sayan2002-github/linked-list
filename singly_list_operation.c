#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}nod;
nod *head, *newnode;

// calculate length of the list
int get_length(){
    nod *temp;
    int count = 0;
    temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

//display function
void display(){
    nod *temp;
    temp = head;
    if(head == 0){
        printf("List is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

// Insertion functions
void insertion_at_beg(){
    newnode = (nod *)malloc(sizeof(nod));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertion_at_end(){
    nod *temp;
    temp = head;
    newnode = (nod *)malloc(sizeof(nod));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

void insertion_at_pos(){
    nod *temp;
    int pos, i = 1, size;
    temp = head;
    size = get_length();
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>size+1){
        printf("Invalid position\n");
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

void insertion(){
    int choice = 1;
    printf("Enter\n1 for insertion at beginning\n2 for at the end\n3 for at specific position\n4 for exit\n5 for display\n");
    while(choice != 4){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Insertion at beginning\n");
                insertion_at_beg();
                break;
            case 2:
                printf("Insertion at end\n");
                insertion_at_end();
                break;
            case 3:
                printf("Insertion at specific position\n");
                insertion_at_pos();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            case 5:
                display();
                break;
            default: printf("Invalid choice\n");
        }
    }
}

// deletion functions
void deletion_at_beg(){
    nod *temp;
    temp = head;
    head = head->next;
    free(temp);
}

void deletion_at_end(){
    int i = 1, count;
    nod *temp, *nextode;
    count = get_length();
    temp = head;
    while(i<count-1){
        temp = temp->next;
        i++;
    }
    nextode = temp->next;
    temp->next = NULL;
    free(nextode);
}

void deletion_at_pos(){
    int pos, i = 1, size;
    nod *temp, *nextode;
    size = get_length();
    temp = head;
    printf("Enter the positon: ");
    scanf("%d",&pos);
    if(pos<1 || pos>size){
        printf("Invalid position\n");
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
        nextode = temp->next;
        temp->next = nextode->next;
        free(nextode);
    }
}

void deletion(){
    int choice = 1;
    printf("Enter\n1 for deletion at beginning\n2 for at the end\n3 for at specific position\n4 for exit\n5 for display\n");
    while(choice != 4){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("deletion at beginning\n");
                deletion_at_beg();
                break;
            case 2:
                printf("deletion at end\n");
                deletion_at_end();
                break;
            case 3:
                printf("deletion at specific position\n");
                deletion_at_pos();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            case 5:
                display();
                break;
            default: printf("Invalid choice\n");
        }
    }
}

// reversal operation
void reversal(){
    nod * prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode != 0){
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

//Driver code
int main()
    {
        int choice = 1;
        nod *temp;
        head = 0;
        while(choice){
            newnode = (nod *)malloc(sizeof(nod));
            printf("\nEnter the data: ");
            scanf("%d",&newnode->data);
            newnode->next = NULL;
            if(head == 0){
                head = temp = newnode;
            }
            else{
                temp->next = newnode;
                temp = temp->next;
            }
            printf("Do you want to continue?: ");
            scanf("%d",&choice);
        }

        printf("Enter\n1 for insertion\n2 for deletion\n3 for reversal\n4 for exit\n5 for display\n");
        while(choice != 4){
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice){
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
                    printf("Exiting...\n");
                    break;
                case 5:
                    display();
                    break;
                default: printf("Invalid choice\n");
            }
        }
        return 0;
    }