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
    int maxi = INT_MIN;
    int traverse(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        int val = root->val;
        val = max(val, left + root->val);
        val = max(val, right + root->val);
        val = max(val, left + right + root->val);
        maxi = max(maxi, val);
        return root->val + max(0, max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        traverse(root);
        return maxi;
    }
};
// PROBLEM:- https://leetcode.com/problems/binary-tree-maximum-path-sum/description
