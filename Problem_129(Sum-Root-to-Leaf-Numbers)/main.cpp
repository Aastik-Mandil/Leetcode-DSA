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
    void traverse(TreeNode *root, int val){
        if(root == NULL){
            ans += val;
            return;
        }
        if(root->left && root->right){
            traverse(root->left, (10*val)+root->val);
            traverse(root->right, (10*val)+root->val);
        }
        else if(root->right){
            traverse(root->right, (10*val)+root->val);
        }
        else if(root->left){
            traverse(root->left, (10*val)+root->val);
        }
        else{
            ans += ((10*val) + root->val);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        traverse(root, 0);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sum-root-to-leaf-numbers/description
