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
    vector<string> v;
    void traverse(TreeNode *root, TreeNode *p, string s){
        if(root==NULL){
            return;
        }
        if(root == p){
            v.push_back(s);
            return;
        }
        traverse(root->left, p, s+"0");
        traverse(root->right, p, s+"1");
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        v.clear();
        traverse(root, p, "");
        traverse(root, q, "");
        if(v.size() < 2){
            return NULL;
        }
        int len = min(v[0].size(), v[1].size());
        TreeNode *curr = root;
        for(int i=0; i<len; i++){
            if(v[0][i] == v[1][i]){
                if(v[0][i] == '0'){
                    curr = curr->left;
                }
                else{
                    curr = curr->right;
                }
            }
            else{
                return curr;
            }
        }
        return curr;
    }
};
// PROBLEM:- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description
