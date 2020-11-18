#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node*next;
    node(int d)
    {
        data = d;
        next = nullptr;
    }
};
void InsertAtTail(node*&head, int d)
{
    if(head == nullptr)
    {
        head = new node(d);
        return;
    }
    node*temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->next = new node(d);
}
void buildList(node*&head)
{
    int d;
    cin>>d;
    while(d != -1)
    {
        InsertAtTail(head, d);
        cin>>d;
    }
}
void printList(node*head)
{
    if(head == nullptr)
        return;
    while(head != nullptr)
    {
        cout<<head->data<<" -> ";
        head = head->next;
    }
}
bool searchIterative(node*head, int d)
{
    if(head == nullptr)
        return false;
    while(head != nullptr)
    {
        if(head->data == d)
            return true;
        head = head->next;
    }
    return false;
}
bool searchRecursive(node*head, int d)
{
    if(head == nullptr)
        return false;
    if(head->data == d)
        return true;
    return searchRecursive(head->next, d);
}
void reverseIterative(node*&head)
{
    if(head == nullptr || head->next == nullptr)
        return;
    node*C = head;
    node*P = nullptr;
    while(C != nullptr)
    {
        node*N = C->next;
        C->next = P;
        P = C;
        C = N;
    }
    head = P;
}
node*reverseRecursive(node*head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    node*smallHead = reverseRecursive(head->next);
    node*C = head;
    C->next->next = C;
    C->next = nullptr;
    return smallHead;
}
int main()
{
    node*head = nullptr;
    buildList(head);
    //cout<<searchIterative(head, 2);
    //cout<<searchRecursive(head, 9);
    //reverseIterative(head);
    head = reverseRecursive(head);
    printList(head);
}
/*
1 2 3 4 5 6 -1
*/
