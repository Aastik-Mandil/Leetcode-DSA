struct Node {
    Node* val[2];
    bool end;

    Node(){
        for(int i=0;i<2;i++){
            val[i] = NULL;
        }
        end=false;
    }

    bool hasKey(int num){
        return val[num] != NULL;
    }

    void add(int num){
        val[num] = new Node();
    }

    Node* get(int num){
        return val[num];
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

        Node* getRoot(){
            return root;
        }

        void insert(int num) {
            Node *node = root;
            for(int i=31;i>=0;i--){
                int ch = (num>>i) & 1;
                if(!node->hasKey(ch)){
                    node->add(ch);
                }
                node = node->get(ch);
            }
            node->setEnd();
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }

        Trie trie = Trie();
        trie.insert(nums[0]);
        int ans = 0;
        for(int i=1;i<n;i++){
            int j=31;
            Node *node = trie.getRoot();
            int res=0;
            while(j>=0){
                int val = (nums[i] >> j) & 1;
                if(node->hasKey(1^val)){
                    res+=pow(2,j);
                    node = node->get(1^val);
                }
                else{
                    node = node->get(val);
                }
                j--;
            }
            ans=max(ans, res);
            trie.insert(nums[i]);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
