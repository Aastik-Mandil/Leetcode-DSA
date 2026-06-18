struct Node {
    Node* val[26];
    int count;
    bool end;

    Node(){
        for(int i=0;i<26;i++){
            val[i] = NULL;
        }
        count = 0;
        end = false;
    }

    bool hasKey(char ch){
        return val[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return val[ch-'a'];
    }

    void add(char ch){
        val[ch-'a'] = new Node();
    }

    int getCount(){
        return count;
    }

    void setCount(int val){
        count = val;
    }

    void setEnd(){
        end = true;;
    }

    int isEnd(){
        return end;
    }
};

class Trie{
    private:
        Node *root;
        unordered_map<string, int> mp;

    public:
        Trie(){
            root = new Node();
            mp.clear();
        }

        Node* getRoot(){
            return root;
        }

        void insert(string word, int val){
            int originalVal = mp[word];
            Node *node = root;
            for(char &ch: word){
                if(!node->hasKey(ch)){
                    node->add(ch);
                }
                node = node->get(ch);
                node->setCount(node->getCount() - originalVal + val);
            }
            node->setEnd();
            mp[word] = val;
        }

        int searchPrefix(string word){
            Node *node = root;
            for(char &ch: word){
                if(!node->hasKey(ch)){
                    return 0;
                }
                node = node->get(ch);
            }
            return node->getCount();
        }
};

class MapSum {
    Trie trie;
public:
    MapSum() {
        trie = Trie();
    }
    
    void insert(string key, int val) {
        trie.insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.searchPrefix(prefix);
    }
};
// PROBLEM:- https://leetcode.com/problems/map-sum-pairs/

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
