#include <bits/stdc++.h>
using namespace std;

// optimal code : USe doubly linked list and Hashmap
class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key1, int value1)
    {
        value = value1;
        key = key1;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
public:
    // Dummy node approach
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> mp;

    // capacity of the cache
    LRUCache(int capacity)
    {
        cap = capacity;
        // connecting head and tail all operations will be in middle of these
        head->next = tail;
        tail->prev = head;
    }

    // deleting a node , i.e connecting prev node of current node to ,  next node of current node
    void deletenode(Node *temp)
    {
        Node *prevnode = temp->prev;
        Node *nextnode = temp->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    // inserting after the head as that node may be accessed or new node in the cache
    void insertafterhead(Node *temp)
    {
        Node *nextnode = head->next;
        nextnode->prev = temp;
        head->next = temp;
        temp->next = nextnode;
        temp->prev = head;
    }

    // getting the value attached to the key
    int get(int key)
    {
        // if key present in map
        if (mp.find(key) != mp.end())
        {
            // getting the node with key given
            Node *findnode = mp[key];
            // accessing the key value
            int val = findnode->value;
            // as the node is accessed means remove it from current location and put after head (high priority)
            deletenode(findnode);
            insertafterhead(findnode);
            return val;
        }
        return -1; // not in map
    }

    // inserting data in cache
    void put(int key, int value)
    {
        // if already in map then just update the value of the key ie value of node  , with the key given
        if (mp.find(key) != mp.end())
        {
            // need node with key
            Node *findnode = mp[key];
            // updaing its value
            findnode->value = value;
            // deleting from previous location
            deletenode(findnode);
            // inserting near head mean priority incresd
            insertafterhead(findnode);
        }
        else
        {
            // if not in map
            // if size == cap means full cache so delete the least recently used node  and insert new node near the head;
            if (mp.size() == cap)
            {
                Node *lastnode = tail->prev;
                deletenode(lastnode);
                mp.erase(lastnode->key);
                Node *temp = new Node(key, value);
                mp[key] = temp;
                insertafterhead(temp);
            }
            else
            {
                Node *temp = new Node(key, value);
                mp[key] = temp;
                insertafterhead(temp);
            }
            // if not full then just insert new node near the head
        }
    }
};

int main()
{
    int capacity = 2;
    LRUCache *obj = new LRUCache(capacity);
    obj->put(1, 1);
    cout << "\nDone put operation for 1,1";
    obj->put(2, 2);
    cout << "\nDone put operation for 2,2";
    int param_1 = obj->get(1);
    cout << "\nGet operation: " << param_1;
    obj->put(3, 3);
    cout << "\nDone put operation for 3,3";
    int param_2 = obj->get(2);
    cout << "\nGet operation: " << param_2;
    obj->put(4, 4);
    cout << "\nDone put operation for 4,4";
    int param_3 = obj->get(1);
    cout << "\nGet operation: " << param_3;
    int param_4 = obj->get(3);
    cout << "\nGet operation: " << param_4;
    int param_5 = obj->get(4);
    cout << "\nGet operation: " << param_5;

    return 0;
}