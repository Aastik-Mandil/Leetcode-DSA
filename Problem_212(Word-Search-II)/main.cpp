struct Node{
    vector<Node*> v;
    string word;
    bool end;

    Node(){
        for(int i=0; i<26; i++){
            v.push_back(NULL);
        }
        end = false;
        word = "";
    }

    bool hasKey(char ch){
        return v[ch-'a'] != NULL;
    }

    void setKey(char ch){
        v[ch-'a'] = new Node();
    }

    Node *getKey(char ch){
        return v[ch-'a'];
    }

    void setEnd(){
        end = true;
    }

    bool isEnd(){
        return end;
    }

    void setWord(string s){
        word = s;
    }

    string getWord(){
        return word;
    }
};

class Trie{
    private:
        Node *root;
    
    public:
        Trie(){
            root = new Node();
        }

        void addWord(string word){
            Node *curr = root;
            for(char &ch: word){
                if(!curr->hasKey(ch)){
                    curr->setKey(ch);
                }
                curr = curr->getKey(ch);
            }
            curr->setEnd();
            curr->setWord(word);
        }

        Node* getRoot(){
            return root;
        }
};

class Solution {
    set<string> res;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool canMove(vector<vector<char>> &board, int n, int m, int r, int c){
        return r>=0 && r<n && c>=0 && c<m && board[r][c] != '#';
    }

    void solve(vector<vector<char>> &board, int n, int m, int r, int c, Node *node){
        if(node == NULL){
            return;
        }
        if(!node->hasKey(board[r][c])){
            return;
        }
        char ch = board[r][c];
        board[r][c] = '#';
        Node *newNode = node->getKey(ch);
        for(vector<int> &dir: dirs){
            int newR = r+dir[0];
            int newC = c+dir[1];
            if(canMove(board, n, m, newR, newC)){
                solve(board, n, m, newR, newC, newNode);
            }
        }
        if(newNode->isEnd()){
            res.insert(newNode->getWord());
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();

        Trie trie = Trie();
        for(string &word: words){
            trie.addWord(word);
        }

        int n = board.size(), m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                solve(board, n, m, i, j, trie.getRoot());
            }
        }

        vector<string> ans;
        for(auto itr=res.begin(); itr!=res.end(); itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/word-search-ii/description
