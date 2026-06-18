// Solution 1
class LRUCache {
    vector<int> v;
    unordered_map<int,int> mp;
    int cap;
public:
    LRUCache(int capacity) {
        v.clear();
        mp.clear();
        cap = capacity;
    }

    int get(int key) {
        auto itr = find(v.begin(), v.end(), key);
        if(itr == v.end()){
            return -1;
        }
        v.erase(itr);
        v.push_back(key);
        return mp[key];
    }

    void put(int key, int value) {
        auto itr = find(v.begin(), v.end(), key);
        if(itr != v.end()){
            v.erase(itr);
        }
        v.push_back(key);
        if(v.size() > cap){
            v.erase(v.begin());
        }
        mp[key] = value;
    }
};

// Solution 2
struct Node{
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    unordered_map<int,Node*> mp;
    Node *head = NULL;
    Node *tail = NULL;
    int cap;

    void insertAfterHead(Node *node){
        Node *headNext = head->next;
        node->next = headNext;
        headNext->prev = node;
        node->prev = head;
        head->next = node;
    }
    void deletionNode(Node *node){
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
public:
    LRUCache(int capacity) {
        mp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node *node = mp[key];
        deletionNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == cap){
                Node *tailPrev = tail->prev;
                mp.erase(tailPrev->key);
                deletionNode(tailPrev);
            }
            Node *curr = new Node(key, value);
            mp[key] = curr;
            insertAfterHead(curr);

        }
        else{
            Node *node = mp[key];
            node->value = value;
            deletionNode(node);
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// PROBLEM:- https://leetcode.com/problems/lru-cache/description/
