#define __STRICT_ANSI__
// #ifdef __clang__
// typedef struct { long double x, y; } __float128;
// #endif
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
struct Node
{   
    int data;
    Node *next;
};
// head in main function is a local variable,pass it is just pass the copy address of head node to Insert
Node *Insert(Node *head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        
        Node *temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

Node* Reverse(Node* p) {
    if (p->next == nullptr) {
        return p;
    }

    Node* newHead = Reverse(p->next);

    

    p->next->next = p;
    
    p->next = nullptr;  // 断开当前节点的下一个指针

    return newHead;
}

void Print(Node *head)
{
    if(head == NULL) return; // exit condition
    printf("\n%d\n", head->data); // first print head node data
    Print(head->next); // recursive call
    
}
void FreeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head =  NULL; // local variabel
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    // printf("\n");
    // Print(head);
    head = Reverse(head);
    Print(head);
    FreeList(head);

}