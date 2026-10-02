/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<vector<int>> v;
        int count = 0, num = 0;
        for(char ch: traversal){
            if(ch == '-'){
                if(num == 0){
                    count++;
                }
                else{
                    // cout<<count<<" "<<num<<endl;
                    v.push_back({count, num});
                    num = 0;
                    count = 1;
                }
            }
            else{
                num = (10*num) + (ch-'0');
            }
        }
        // cout<<count<<" "<<num<<endl;
        v.push_back({count, num});

        TreeNode *root = new TreeNode(v[0][1]);
        stack<pair<int,TreeNode*>> st;
        st.push({v[0][0], root});
        int idx = 1;
        while(st.size()>0 && idx<v.size()){
            int cnt = st.top().first;
            TreeNode *node = st.top().second;
            if(cnt+1 == v[idx][0]){
                if(node->left){
                    TreeNode *right = new TreeNode(v[idx][1]);
                    node->right = right;
                    st.pop();
                    st.push({v[idx][0], right});
                }
                else{
                    TreeNode *left = new TreeNode(v[idx][1]);
                    node->left = left;
                    st.push({v[idx][0], left});
                }
                idx++;
            }
            else{
                st.pop();
            }
        }
        return root;
    }
};
// PROBLEM:- https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/
