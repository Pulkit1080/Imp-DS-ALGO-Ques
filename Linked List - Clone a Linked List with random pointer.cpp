//GFG

Node *copyList(Node *head)
{
    if(head == nullptr)
        return head;
    //Create new Nodes between original nodes
    Node*nCurr = head;
    while(nCurr != nullptr)
    {
        Node*temp = new Node(nCurr->data);
        temp->next = nCurr->next;
        nCurr->next = temp;
        nCurr = nCurr->next->next;
    }
    //Copy random(arbitrary) pointers
    nCurr = head;
    while(nCurr != nullptr)
    {
        if(nCurr->arb == nullptr)       // if arbitrary pointer of node is nullptr
        {
            nCurr->next->arb = nullptr;
        }
        else
        {
            nCurr->next->arb = nCurr->arb->next;
        }
        nCurr = nCurr->next->next;
    }
    //Separate new and old nodes
    nCurr = head;
    Node*copy = head->next;
    while(nCurr->next != nullptr)
    {
        Node*temp = nCurr->next;
        nCurr->next = nCurr->next->next;
        nCurr = temp;
    }
    return copy;
}
