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

        void getAllWords(Node *node, vector<string> &res, string z){
            if(node == NULL || res.size() == 3){
                return;
            }
            if(node->isEnd()){
                res.push_back(z);
            }
            for(char ch='a';ch<='z';ch++){
                if(node->hasKey(ch)){
                    z.push_back(ch);
                    getAllWords(node->get(ch), res, z);
                    z.pop_back();
                }
            }
        }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        for(string &product: products){
            trie.insert(product);
        }

        Node *node = trie.getRoot();
        vector<vector<string>> ans;
        string z="";
        for(char &ch: searchWord){
            if(node && node->hasKey(ch)){
                node = node->get(ch);
                z.push_back(ch);
                vector<string> res;
                trie.getAllWords(node, res, z);
                ans.push_back(res);
            }
            else{
                node = NULL;
                ans.push_back({});
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/search-suggestions-system/
