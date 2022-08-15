#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} nod;
nod *head, *tail, *temp;

void display(){
    temp = head;
    while(temp->next != head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}

int main()
{
    nod *newnode;
    int choice = 1;
    head = 0;
    while (choice)
    {
        newnode = (nod *)malloc(sizeof(nod));
        printf("\nEnter the data of newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue?: ");
        scanf("%d",&choice);
    }
    // tail = temp;
    temp->next = head;

    display();

    return 0;
}