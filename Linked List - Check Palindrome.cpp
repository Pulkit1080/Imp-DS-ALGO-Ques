//GFG

Node*midNode(Node*head)
{
    Node*slow = head;
    Node*fast = head;
    Node*prev = nullptr;
    while(fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* rev(struct Node *head)
{
    // code here
    // return head of reversed list
    if(head == nullptr || head->next == nullptr)
        return head;
    Node*p = nullptr;
    Node*c = head;
    while(c != nullptr)
    {
        Node*n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}
bool isPalindrome(Node *l1)
{
    //Your code here
    Node*l2 = midNode(l1);
    l2 = rev(l2);
    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1->data != l2->data)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}
