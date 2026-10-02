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
    int traverse(TreeNode *root, int maxiVal){
        if(root == NULL){
            return 0;
        }
        if(maxiVal <= root->val){
            return 1 + traverse(root->left, root->val) + traverse(root->right, root->val);
        }
        return traverse(root->left, maxiVal) + traverse(root->right, maxiVal);
    }
public:
    int goodNodes(TreeNode* root) {
        return traverse(root, INT_MIN);
    }
};
// PROBLEM:- https://leetcode.com/problems/count-good-nodes-in-binary-tree/description
