/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    string findPath(TreeNode *root, TreeNode *node){
        if(root == NULL){
            return "";
        }
        if(root->val == node->val){
            return "";
        }
        if(root->val > node->val){
            return "0"+findPath(root->left, node);
        }
        return "1"+findPath(root->right, node);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        string s1 = findPath(root, p);
        string s2 = findPath(root, q);
        TreeNode *ans = root;
        for(int i=0;i<s1.size() && i<=s2.size();i++){
            if(s1[i] == s2[i]){
                if(s1[i] == '0'){
                    ans = ans->left;
                }
                else{
                    ans = ans->right;
                }
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
