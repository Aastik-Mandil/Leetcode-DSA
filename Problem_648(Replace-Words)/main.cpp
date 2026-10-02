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

        string findSmallest(string word){
            string ans="";
            Node *node = root;
            for(char &ch: word){
                if(!node->hasKey(ch)){
                    return word;
                }
                node = node->get(ch);
                ans.push_back(ch);
                if(node->isEnd()){
                    return ans;
                }
            }
            return ans;
        }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie = Trie();
        for(string &word: dictionary){
            trie.insert(word);
        }

        string ans="", z="";
        for(char &ch: sentence){
            if(ch ==' '){
                string s = trie.findSmallest(z);
                ans+=s + " ";
                z="";
            }
            else{
                z.push_back(ch);
            }
        }
        return ans + trie.findSmallest(z);
    }
};
// PROBLEM:- https://leetcode.com/problems/replace-words/
