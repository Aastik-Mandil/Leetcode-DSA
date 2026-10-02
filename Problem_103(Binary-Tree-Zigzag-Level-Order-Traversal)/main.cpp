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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1, st2;
        if(root){
            st1.push(root);
        }
        vector<vector<int>> ans;
        while(st1.size() > 0 || st2.size()>0){
            vector<int> z1;
            while(st1.size()>0){
                TreeNode *node = st1.top();
                st1.pop();
                z1.push_back(node->val);
                if(node->left){
                    st2.push(node->left);
                }
                if(node->right){
                    st2.push(node->right);
                }
            }
            if(z1.size()>0){
                ans.push_back(z1);
            }

            vector<int> z2;
            while(st2.size()>0){
                TreeNode *node = st2.top();
                st2.pop();
                z2.push_back(node->val);
                if(node->right){
                    st1.push(node->right);
                }
                if(node->left){
                    st1.push(node->left);
                }
            }
            if(z2.size()>0){
                ans.push_back(z2);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description
