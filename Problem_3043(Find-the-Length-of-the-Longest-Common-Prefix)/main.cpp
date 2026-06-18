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

        int maxLength(string word){
            Node *node = root;
            int count = 0;
            for(char &ch: word){
                if(!node->hasKey(ch)){
                    break;
                }
                node = node->get(ch);
                count++;
            }
            return count;
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Trie trie = Trie();
        for(int &num: arr1){
            string s = to_string(num);
            trie.insert(s);
        }

        for(int &num: arr2){
            string s = to_string(num);
            ans = max(ans, trie.maxLength(s));
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
