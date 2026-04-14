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
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int lh = 0, rh = 0;
        if(root->left){
            lh = height(root->left);
        }
        if(root->right){
            rh = height(root->right);
        }
        return 1 + max(lh, rh);
    }
    bool solveBF(TreeNode *root){
        if(root == NULL){
            return true;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh) > 1){
            return false;
        }
        bool left = solveBF(root->left);
        bool right = solveBF(root->right);
        return left && right;
    }

    int solveO(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int lh = solveO(root->left);
        int rh = solveO(root->right);
        if(lh == -1 || rh == -1){
            return -1;
        }
        if(abs(lh-rh) > 1){
            return -1;
        }
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        // return solveBF(root);

        return solveO(root) != -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/balanced-binary-tree/description/
