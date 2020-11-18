//  GFG

class Node
{
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v)
    {
        key = k;
        value = v;
    }
};

// design the class:

class LRUCache
{
private:
    map<int, Node*>mp;
    Node* head;
    Node* tail;
    int size;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        size = cap;
        head = tail = nullptr;

        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
    }

    int get(int key)
    {
        // this function should return value corresponding to key
        if(mp.find(key) != mp.end())
        {
            auto it = mp.find(key);
            Node* node = it->second;
            int res = node->value;
            remove(node);
            add(node);
            return res;
        }
        return -1;
    }

    void set(int key, int value)
    {
        // storing key, value pair
        if(mp.find(key) != mp.end())
        {
            auto it = mp.find(key);
            Node* node = it->second;
            node->value = value;
            remove(node);
            add(node);
        }
        else
        {
            if(mp.size() == size)
            {
                mp.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node*node = new Node(key, value);
            mp.insert({key, node});
            add(node);
        }
    }

    void add(Node* node)
    {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void remove(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};
