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
    int solveR(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int notTaken = solveR(root->left) + solveR(root->right);
        int taken = root->val;
        if(root->left){
            taken += solveR(root->left->left) + solveR(root->left->right);
        }
        if(root->right){
            taken += solveR(root->right->left) + solveR(root->right->right);
        }
        return max(taken, notTaken);
    }
    int solveM(TreeNode *root, unordered_map<TreeNode*, int> &mp){
        if(root == NULL){
            return 0;
        }
        if(mp[root] > 0){
            return mp[root];
        }
        int notTaken = solveM(root->left, mp) + solveM(root->right, mp);
        int taken = root->val;
        if(root->left){
            taken += solveM(root->left->left, mp) + solveM(root->left->right, mp);
        }
        if(root->right){
            taken += solveM(root->right->left, mp) + solveM(root->right->right, mp);
        }
        return mp[root] = max(taken, notTaken);
    }
public:
    int rob(TreeNode* root) {
        // return solveR(root);

        unordered_map<TreeNode*, int> mp;
        return solveM(root, mp);
    }
};
// PROBLEM:- https://leetcode.com/problems/house-robber-iii/description/
