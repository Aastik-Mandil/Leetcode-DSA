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
    int getMinimumDifference(TreeNode* root) {
        z.clear();
        traversal(root);

        int ans = INT_MAX;
        for(int i=1;i<z.size();i++){
            ans = min(ans, z[i]-z[i-1]);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-absolute-difference-in-bst/description
