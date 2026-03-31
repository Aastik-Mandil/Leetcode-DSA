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

bool cond(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        sort(queries.begin(),queries.end(),cond);
        sort(nums.begin(),nums.end());

        Trie trie = Trie();
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m,-1);
        int ind = 0;
        for(vector<int> &query: queries){
            int x = query[0];
            int m = query[1];
            int idx = query[2];

            while(ind<n && nums[ind]<=m){
                trie.insert(nums[ind]);
                ind++;
            }

            int j=31;
            Node *node = trie.getRoot();
            int res = 0;
            while(j>=0){
                int val = (x >> j) & 1;
                if(node->hasKey(1^val)){
                    res+=pow(2,j);
                    node = node->get(1^val);
                }
                else{
                    node = node->get(val);
                }
                if(node == NULL){
                    break;
                }
                j--;
            }
            ans[idx] = (ind == 0 || j >= 0) ? -1 : res;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
