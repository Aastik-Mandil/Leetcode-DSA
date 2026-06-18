struct Node {
    Node* val[26];
    int count;

    Node(){
        for(int i=0;i<26;i++){
            val[i] = NULL;
        }
        count=0;
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

    void increaseCount(){
        count++;
    }

    int getCount(){
        return count;
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
                node->increaseCount();
            }
        }

        string findLongestCommon(string word, int count){
            string ans="";
            Node *node = root;
            for(char &ch: word){
                node = node->get(ch);
                if(node->getCount() != count){
                    break;
                }
                ans.push_back(ch);
            }
            return ans;
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie = Trie();
        for(string &word: strs){
            trie.insert(word);
        }

        string s = strs[0];
        return trie.findLongestCommon(s, strs.size());
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-common-prefix/
