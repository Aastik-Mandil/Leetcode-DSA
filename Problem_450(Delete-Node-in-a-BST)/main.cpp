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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == val){
            if(root->left && root->right){
                TreeNode *right = root->right;
                while(right->left){
                    right = right->left;
                }
                root->val = right->val;
                right->val = val;
            }
            else if(root->left){
                return root->left;
            }
            else if(root->right){
                return root->right;
            }
            else{
                return NULL;
            }
        }
        root->left = deleteNode(root->left, val);
        root->right = deleteNode(root->right, val);
        return root;
    }
};
// PROBLEM:- https://leetcode.com/problems/delete-node-in-a-bst/description
