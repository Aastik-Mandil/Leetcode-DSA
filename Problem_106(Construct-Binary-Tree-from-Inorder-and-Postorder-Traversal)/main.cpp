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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &idx, int st, int ed){
        if(idx<0){
            return NULL;
        }
        if(st > ed){
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[idx]);
        int index = findElement(inorder, postorder[idx], st, ed);
        if(index == -1){
            return NULL;
        }
        idx--;
        root->right = solve(inorder, postorder, idx, index+1, ed);
        root->left = solve(inorder, postorder, idx, st, index-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ed = postorder.size()-1;
        return solve(inorder, postorder, ed, 0, inorder.size()-1);
    }
};
// PROBLEM:- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description
