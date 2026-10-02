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

    Node* get(char ch){
        return val[ch-'a'];
    }

    void add(char ch){
        val[ch-'a'] = new Node();
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
    public:
        Trie(){
            root = new Node();
        }

        Node* getRoot(){
            return root;
        }

        void insert(string word){
            Node *node = root;
            for(char &ch: word){
                if(!node->hasKey(ch)){
                    node->add(ch);
                }
                node = node->get(ch);
            }
            node->setEnd();
        }

        bool search(string word, int idx, int count, Node *node){
            if(node==NULL){
                return false;
            }
            if(idx==word.size()){
                return count==0 && node && node->isEnd();
            }
            for(int i=0;i<26;i++){
                if(node->hasKey(word[idx]) && (i+'a')==word[idx]){
                    if(search(word, idx+1, count, node->get(i+'a'))){
                        return true;
                    }
                }
                else{
                    if(count>0 && search(word, idx+1, count-1, node->get(i+'a'))){
                        return true;
                    }
                }
            }
            return false;
        }
};

class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() {
        trie = Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string &word: dictionary){
            trie.insert(word);
        }
    }
    
    bool search(string searchWord) {
        return trie.search(searchWord, 0, 1, trie.getRoot());
    }
};
// PROBLEM:- https://leetcode.com/problems/implement-magic-dictionary/description/

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
