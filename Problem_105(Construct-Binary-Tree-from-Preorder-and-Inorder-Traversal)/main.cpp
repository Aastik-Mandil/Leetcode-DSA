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
    int findElement(vector<int> &inorder, int ele, int st, int ed){
        for(int i=st; i<=ed; i++){
            if(inorder[i] == ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &idx, int st, int ed){
        if(idx >= preorder.size()){
            return NULL;
        }
        if(st > ed){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[idx]);
        int index = findElement(inorder, preorder[idx], st, ed);
        if(index == -1){
            return NULL;
        }
        idx++;
        root->left = solve(inorder, preorder, idx, st, index-1);
        root->right = solve(inorder, preorder, idx, index+1, ed);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int st = 0;
        return solve(inorder, preorder, st, 0, inorder.size()-1);
    }
};
// PROBLEM:- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description
