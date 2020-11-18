//LEETCODE

/*
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int>ans;
        stack<Node*>s;
        if(root == nullptr)
            return ans;
        s.push(root);
        while(!s.empty())
        {
            Node*node = s.top();
            s.pop();
            ans.push_back(node->val);
            reverse(node->children.begin(), node->children.end());
            for(auto child:node->children)
                s.push(child);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> postorder(Node* root)
    {
        vector<int>ans;
        list<int>ans_list;
        stack<Node*>s;
        if(root == nullptr)
            return ans;
        s.push(root);
        while(!s.empty())
        {
            Node*node = s.top();
            s.pop();
            ans_list.push_front(node->val);
            for(auto child:node->children)
                s.push(child);
        }
        for(int it:ans_list)
            ans.push_back(it);
        return ans;
    }
};
