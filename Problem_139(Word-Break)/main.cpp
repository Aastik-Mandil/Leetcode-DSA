struct Node{
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

    bool isEnd(){
        return end;
    }

    void setEnd(){
        end = true;
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

        Node* getRoot(){
            return root;
        }

        bool canBreak(string word, Node *node, int idx){
            if(idx==word.size()){
                return node->isEnd();
            }
            if(!node->hasKey(word[idx])){
                return false;
            }
            if(node->isEnd()){
                if(node->hasKey(word[idx])){
                    if(canBreak(word, node->get(word[idx]), idx+1)){
                        return true;
                    }
                    // return canBreak(word, root, idx) || ;
                }
                return canBreak(word, root, idx);
            }
            return canBreak(word, node->get(word[idx]), idx+1);
        }
};

class Solution {
    bool wordBreakR(string &s, vector<string> &wordDict, int idx){
        if(idx == s.size()){
            return true;
        }
        for(string &word: wordDict){
            if(s.substr(idx, word.size()) == word){
                if(wordBreakR(s, wordDict, min(idx+word.size(), s.size()))){
                    return true;
                }
            }
        }
        return false;
    }
    int wordBreakM(string &s, vector<string> &wordDict, int idx, vector<int> &dp){
        if(idx == s.size()){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        for(string &word: wordDict){
            if(s.substr(idx, word.size()) == word){
                if(wordBreakM(s, wordDict, min(idx+word.size(), s.size()), dp) == 1){
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
    int wordBreakT(string &s, vector<string> &wordDict){
        vector<int> dp(s.size()+1, 0);
        dp[s.size()] = 1;
        for(int idx=s.size()-1;idx>=0;idx--){
            for(string &word: wordDict){
                if(s.substr(idx, word.size()) == word){
                    if(dp[min(idx+word.size(), s.size())] == 1){
                        dp[idx] = 1;
                    }
                }
            }
        }
        return dp[0];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Trie trie = Trie();
        // for(string &word: wordDict){
        //     trie.insert(word);
        // }
        // return trie.canBreak(s, trie.getRoot(), 0);

        // return wordBreakR(s, wordDict, 0);

        // vector<int> dp(s.size()+1, -1);
        // return wordBreakM(s, wordDict, 0, dp) == 1;

        return wordBreakT(s, wordDict) == 1;
    }
};
// PROBLEM:- https://leetcode.com/problems/word-break/description/
