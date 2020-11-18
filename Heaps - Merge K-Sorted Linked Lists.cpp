//  GFG

Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       priority_queue<int, vector<int>, greater<int>>pq;
       for(int i = 0;i < N;i++)
       {
           Node* head = arr[i];
           while(head != nullptr)
           {
               pq.push(head->data);
               head = head->next;
           }
       }
       while(!pq.empty())
       {
           cout<<pq.top()<<" ";
           pq.pop();
       }
       return nullptr;
}
