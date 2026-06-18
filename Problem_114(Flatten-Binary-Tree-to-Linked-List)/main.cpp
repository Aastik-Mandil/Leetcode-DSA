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
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode *right = root->right;
        TreeNode *ptr = root->left;
        root->right = ptr;
        while(ptr && ptr->right){
            ptr = ptr->right;
        }
        if(ptr){
            ptr->right = right;
        }
        else{
            root->right = right;
        }
        root->left = NULL;
    }
};
// PROBLEM:- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description
