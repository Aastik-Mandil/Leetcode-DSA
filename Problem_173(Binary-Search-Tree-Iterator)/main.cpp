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
class BSTIterator {
    vector<int> v;
    int idx;
    void traverse(TreeNode *root){
        if(root == NULL){
            return ;
        }
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        idx = 0;
        traverse(root);
    }
    
    int next() {
        int val = v[idx];
        idx++;
        return val;
    }
    
    bool hasNext() {
        return idx<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// PROBLEM:- https://leetcode.com/problems/binary-search-tree-iterator/description
