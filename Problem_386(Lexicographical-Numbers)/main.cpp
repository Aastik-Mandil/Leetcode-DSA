struct Node{
    Node* val[10];
    bool end;

    Node(){
        for(int i=0;i<10;i++){
            val[i] = NULL;
        }
        end = false;
    }

    bool hasKey(char ch){
        return val[ch-'0'] != NULL;
    }

    Node* get(char ch){
        return val[ch-'0'];
    }

    void add(char ch){
        val[ch-'0'] = new Node();
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

        void traverse(vector<int> &ans, Node* node, int val){
            if(node==NULL){
                return;
            }
            if(node->isEnd()){
                ans.push_back(val);
            }
            for(int i=0;i<10;i++){
                if(node->hasKey(i+'0')){
                    traverse(ans, node->get(i+'0'), (10*val)+i);
                }
            }
        }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie trie = Trie();
        for(int i=1;i<=n;i++){
            string word = to_string(i);
            trie.insert(word);
        }

        vector<int> ans;
        trie.traverse(ans, trie.getRoot(), 0);
        return ans;
    }
};
