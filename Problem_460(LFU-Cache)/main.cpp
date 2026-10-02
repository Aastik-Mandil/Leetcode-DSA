struct Node{
    int key;
    int value;
    int count;
    Node *prev;
    Node *next;

    Node(int k, int v){
        key = k;
        value = v;
        count = 1;
        prev = NULL;
        next = NULL;
    }
};

struct LRU{
    Node *head = NULL;
    Node *tail = NULL;
    int cap = 0;

    LRU(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = 0;
    }

    void deleteNode(Node *node){
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
        cap--;
    }

    void deleteLastNode(){
        if(cap == 0){
            return;
        }
        Node *tailPrev = tail->prev;
        deleteNode(tailPrev);
    }

    void insertAfterHead(Node *node){
        Node *headNext = head->next;
        node->next = headNext;
        headNext->prev = node;
        node->prev = head;
        head->next = node;
        cap++;
    }
};

class LFUCache {
    map<int,Node*> freq;
    map<int, LRU> mp;
    int cap = 0;
    int initialFreq = 1;
public:
    LFUCache(int capacity) {
        freq.clear();
        mp.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if(freq.find(key) == freq.end()){
            return -1;
        }
        Node *node = freq[key];
        mp[node->count].deleteNode(node);
        node->count+=1;
        mp[node->count].insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(freq.find(key) == freq.end()){
            // node doesn't exists
            if(freq.size() == cap){
                while(mp[initialFreq].cap == 0){
                    initialFreq++;
                }
                Node *lastPrev = mp[initialFreq].tail->prev;
                freq.erase(lastPrev->key);
                mp[initialFreq].deleteLastNode();
            }

            Node *node = new Node(key, value);
            initialFreq = 1;
            freq[key] = node;
            mp[node->count].insertAfterHead(node);
        }
        else{
            // node exists
            Node *node = freq[key];
            node->value = value;
            mp[node->count].deleteNode(node);
            node->count+=1;
            mp[node->count].insertAfterHead(node);
            while(mp[initialFreq].cap == 0){
                initialFreq++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// PROBLEM:- https://leetcode.com/problems/lfu-cache/description/
