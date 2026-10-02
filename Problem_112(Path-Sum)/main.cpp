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
    int ans = 0;
    bool traverse(TreeNode *root, int target){
        if(root == NULL){
            return target == 0;
        }
        if(root->left && root->right){
            return traverse(root->left, target - root->val) || traverse(root->right, target - root->val);
        }
        if(root->right){
            return traverse(root->right, target - root->val);
        }
        if(root->left){
            return traverse(root->left, target - root->val);
        }
        return target == root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return traverse(root, targetSum);
    }
};
// PROBLEM:- https://leetcode.com/problems/path-sum/description
