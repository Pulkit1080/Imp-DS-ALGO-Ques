//GFG

void deleteNode(Node *node)
{
   // Your code here
   if(node == nullptr)
   {
       return;
   }
   node->data = node->next->data;
   Node*temp = node->next;
   node->next = node->next->next;
   delete temp;
}
