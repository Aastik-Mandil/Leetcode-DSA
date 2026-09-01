struct Node {
    Node* val[26];
    bool end;

    Node(){
        for(int i=0;i<26;i++){
            val[i] = NULL;
        }
        end = false;
    }

    bool hasKey(char ch){
        return val[ch-'a'] != NULL;
    }

    void add(char ch){
        val[ch-'a'] = new Node();
    }

    Node* get(char ch){
        return val[ch-'a'];
    }

    void setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char &ch: word){
            if(!node->hasKey(ch)){
                node->add(ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char &ch: word){
            if(!node->hasKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char &ch: prefix){
            if(!node->hasKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1964694172/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
