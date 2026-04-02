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

        bool search(string word){
            Node *node = root;
            for(char &ch: word){
                node = node->get(ch);
                if(!node->isEnd()){
                    return false;
                }
            }
            return true;
        }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie = Trie();
        for(string &word: words){
            trie.insert(word);
        }

        string ans="";
        for(string &word: words){
            if((word.size() > ans.size()) || (word.size() == ans.size() && ans > word)){
                if(trie.search(word)){
                    ans = word;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-word-in-dictionary/description/
