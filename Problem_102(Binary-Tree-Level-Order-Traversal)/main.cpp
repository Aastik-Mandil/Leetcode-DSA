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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        vector<vector<int>> ans;
        while(q.size() > 0){
            int n = q.size();
            vector<int> z;
            while(n--){
                TreeNode *node = q.front();
                q.pop();
                z.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(z.size()>0){
                ans.push_back(z);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/binary-tree-level-order-traversal/description
