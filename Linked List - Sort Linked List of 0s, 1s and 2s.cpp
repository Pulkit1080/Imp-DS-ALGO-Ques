//GFG

Node* segregate(Node *head)
{
    // Add code here
    Node*zero = new Node(-1);
    Node*zeroHead = zero;
    Node*one = new Node(-1);
    Node*oneHead = one;
    Node*two = new Node(-1);
    Node*twoHead = two;
    while(head != nullptr)
    {
        if(head->data == 0)
        {
            zero->next = head;
            zero = zero->next;
        }
        else if(head->data == 1)
        {
            one->next = head;
            one = one->next;
        }
        else if(head->data == 2)
        {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }
    if(oneHead->next == nullptr && twoHead->next == nullptr)
    {
        zero->next = nullptr;
    }
    else if(oneHead->next != nullptr && twoHead->next != nullptr)
    {
        zero->next = oneHead->next;
        one->next = twoHead->next;
        two->next = nullptr;
    }
    else if(oneHead->next == nullptr)
    {
        zero->next = twoHead->next;
        two->next = nullptr;
    }
    else if(twoHead->next == nullptr)
    {
        zero->next = oneHead->next;
        one->next = nullptr;
    }
    return zeroHead->next;
}
