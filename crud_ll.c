//CRUD operations on singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* head=NULL;


void insertAtBeginning(int value) 
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}


void insertAtEnd(int value) 
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if (head==NULL) 
    {
        head=newNode;
    } 
    else 
    {
        Node* temp=head;
        while (temp->next!=NULL) 
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}


void insertAtPosition(int position, int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    if (position==1) 
    {
        newNode->next=head;
        head=newNode;
    } 
    else 
    {
        Node* temp=head;
        for (int i=1;i<position-1;i++) 
        {
            if (temp==NULL) 
            {
                printf("Invalid position");
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}


void display() 
{
    if (head==NULL) 
    {
        printf("\n");
        return;
    }
    Node* temp=head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void updateAtPosition(int position, int newValue) 
{
    Node* temp=head;
    for (int i=1; i<position; i++) {
        if (temp==NULL) {
            printf("Invalid position");
            return;
        }
        temp=temp->next;
    }
    if (temp==NULL) 
    {
        printf("Invalid position");
    } 
    else 
    {
        temp->data=newValue;
    }
}


void deleteAtBeginning() 
{
    if (head==NULL) {
        printf("List is empty");
        return;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
    
}


void deleteAtEnd() 
{
    if (head==NULL) 
    {
        printf("List is empty");
        return;
    }
    if (head->next==NULL) 
    {
        free(head);
        head=NULL;
        return;
    }
    Node* temp=head;
    while (temp->next!=NULL && temp->next->next!=NULL) 
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    
}


void deleteAtPosition(int position) 
{
    if (head==NULL) 
    {
        printf("List is empty");
        return;
    }
    if (position==1) 
    {
        Node* temp=head;
        head=head->next;
        free(temp);
        display();
        return;
    }
    Node* temp=head;
    for (int i=1; i<position-1; i++) 
    {
        if (temp==NULL || temp->next==NULL) 
        {
            printf("Invalid position");
            return;
        }
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    if (deleteNode==NULL) 
    {
        printf("Invalid position");
        return;
    }
    temp->next=deleteNode->next;
    free(deleteNode);
    display();
}

int main() 
{
    int n;
    printf("Enter no. of operations to perform: ");
    scanf("%d",&n);
    while (n--) 
    {
        int operation;
        printf("Enter the operation: ");
        scanf("%d",&operation);
        switch (operation) 
        {
            case 1: {
                int x;
                scanf("%d",&x);
                insertAtEnd(x);
                break;
            }
            case 2: {
                int x;
                scanf("%d",&x);
                insertAtBeginning(x);
                break;
            }
            case 3: {
                int pos, x;
                scanf("%d %d",&pos,&x);
                insertAtPosition(pos,x);
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                int pos, x;
                scanf("%d %d",&pos,&x);
                updateAtPosition(pos,x);
                break;
            }
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8: {
                int pos;
                scanf("%d",&pos);
                deleteAtPosition(pos);
                break;
            }
            default:
                printf("Invalid operation");
                break;
        }
    }
}
