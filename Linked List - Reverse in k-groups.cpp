//GFG
/*
a[] = 1 2 3 4 5
k = 3
ans = 3 2 1 5 4
a[] = 1 2 3 4 5 6 7 8
k = 4
ans = 4 3 2 1 8 7 6 5
*/
struct node*rev(struct node*begin, struct node*end)
{
    struct node*p = begin;
    struct node*c = begin->next;
    struct node*firstNode = c;
    while(c != end)
    {
        node*n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    begin->next = p;
    firstNode->next = c;
    return firstNode;
}
struct node *reverse (struct node *head, int k)
{
    // Complete this method
    int i = 0;
    struct node*temp = new node(0);
    temp->next = head;
    struct node*begin = temp;
    while(head != nullptr)
    {
        i++;
        if(i%k == 0 || head->next == nullptr)
        {
            begin = rev(begin, head->next);
            head = begin->next;
        }
        else
            head = head->next;
    }
    return temp->next;
}
