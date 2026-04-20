struct Node {
    Node* val[26];
    bool end;

    Node(){
        for(int i=0;i<26;i++){
            val[i] = NULL;
        }
        end=false;
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

    bool isEnd(){
        return end;
    }

    void setEnd(){
        end = true;
    }
};

class WordDictionary {
private:
    Node *root;
    bool find(Node *node, string &s, int idx){
        if(idx==s.size()){
            return node->isEnd();
        }
        if(s[idx]!='.'){
            if(!node->hasKey(s[idx])){
                return false;
            }
            return find(node->get(s[idx]), s, idx+1);
        }
        for(int i=0;i<26;i++){
            if(!node->hasKey('a'+i)){
                continue;
            }
            if(find(node->get('a'+i), s, idx+1)){
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
        return find(root, word, 0);
    }
};
// PROBLEM:- https://leetcode.com/problems/design-add-and-search-words-data-structure/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
