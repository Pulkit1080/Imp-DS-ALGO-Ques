//GFG

Node* rev(Node*head)
{
    Node*c = head;
    Node*p = nullptr;
    while(c != nullptr)
    {
        Node*n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    Node*l1 = rev(first);
    Node*l2 = rev(second);
    Node*start = nullptr;
    Node*end = nullptr;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr)
    {
        int sum = 0;
        if(l1 != nullptr)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        if(sum < 10)
            carry = 0;
        else if(sum > 9)
        {
            sum %= 10;
            carry = 1;
        }
        if(start == nullptr)
        {
            start = new Node(sum);
            end = start;
        }
        else
        {
            end->next = new Node(sum);
            end = end->next;
        }
    }
    if(carry)
    {
        end->next = new Node(1);
        end = end->next;
    }
    start = rev(start);
    return start;
}
