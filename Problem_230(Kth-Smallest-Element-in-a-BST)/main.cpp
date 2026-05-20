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
    vector<int> z;
    void traversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        traversal(root->left);
        z.push_back(root->val);
        traversal(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        z.clear();
        traversal(root);

        if(k>z.size()){
            return -1;
        }
        return z[k-1];
    }
};
// PROBLEM:- https://leetcode.com/problems/kth-smallest-element-in-a-bst/description
