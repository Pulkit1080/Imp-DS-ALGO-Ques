//GFG
void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(root == nullptr)
    {
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right,A);
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize_util(vector<int> &A,int &i)
{
   //Your code here
    if(i == A.size() || A[i] == -1)
    {
        i++;
        return nullptr;
    }
    Node*root = new Node(A[i]);
    i++;
    root->left = deSerialize_util(A,i);
    root->right = deSerialize_util(A,i);
    return root;
}
Node * deSerialize(vector<int>&A)
{
    int i = 0;
    return deSerialize_util(A, i);
}
