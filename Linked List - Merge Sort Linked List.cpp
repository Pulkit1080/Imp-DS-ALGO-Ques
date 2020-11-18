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
node*midNode(node*head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    node*slow = head;
    node*fast = head->next;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node*merge(node*a, node*b)
{
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;
    node*c;
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
node*mergeSort(node*head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    node*mid = midNode(head);
    node*a = head;
    node*b = mid->next;
    mid->next = nullptr;

    a = mergeSort(a);
    b = mergeSort(b);
    node*c = merge(a,b);
    return c;
}
int main()
{
    node* head = nullptr;
    buildList(head);
    head = mergeSort(head);
    printList(head);
}
/*
12 0 98 17 34 43 99 76 100 12 34 -1
*/
