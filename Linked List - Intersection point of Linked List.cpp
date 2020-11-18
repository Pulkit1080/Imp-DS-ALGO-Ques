//GFG

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1 == nullptr || head2 == nullptr)
        return -1;
    Node*s1 = head1;
    Node*s2 = head2;
    while(s1 != s2)
    {
        if(s1 == nullptr)
            s1 = head2;
        else if(s1 != nullptr)
            s1 = s1->next;
        if(s2 == nullptr)
            s2 = head1;
        else if(s2 != nullptr)
            s2 = s2->next;
    }
    if(s1 == nullptr)
        return -1;
    return s1->data;
}
