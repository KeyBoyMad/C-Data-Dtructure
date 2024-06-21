#define __STRICT_ANSI__
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
//doubly linked list just need a single pointer to look up previous node and next node,also current node.
struct Node
{   
    int data;
    Node *next;
    Node *prev;
};

Node *head; // global variable

Node *GetNewNode(int x)
{
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void InsertAtHead(int x)
{
    Node *newnode = GetNewNode(x);
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    head->prev = newnode; // first node previous linked to newnode(<-) 
    newnode->next = head;// newnode next linked to head node(which is second node)(->)
    head = newnode; // reset head node
}   

void
void Print()
{
    Node *temp = head;
    printf("Forward:");
    while(temp != NULL)
    {   
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversPrint()
{
    Node *temp = head;
    // Going to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse:");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");

    
}

int main()
{
    head = NULL;
    InsertAtHead(2);
    Print();
    ReversPrint();
    InsertAtHead(4);
    Print();
    ReversPrint();
    InsertAtHead(6);
    Print();
    ReversPrint();

} 