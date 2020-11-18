//GFG

Node* pairWiseSwap(struct Node* head)
{
    // The task is to complete this method
    Node* temp = new Node(0);
    temp->next = head;
    Node*C = temp;
    while(C->next != nullptr && C->next->next != nullptr)
    {
        Node*f = C->next;
        Node*s = C->next->next;
        C->next = s;
        f->next = s->next;
        s->next = f;
        C = C->next->next;
    }
    return temp->next;
}
