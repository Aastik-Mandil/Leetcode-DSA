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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        depth--;
        int count = 1;
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        while(q.size() > 0){
            int n = q.size();
            while(n--){
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left){
                    if(count == depth){
                        TreeNode *node = new TreeNode(val);
                        node->left = curr->left;
                        curr->left = node;
                    }
                    else{
                        q.push(curr->left);
                    }
                }
                else{
                    if(count == depth){
                        TreeNode *node = new TreeNode(val);
                        node->left = curr->left;
                        curr->left = node;
                    }
                }
                if(curr->right){
                    if(count == depth){
                        TreeNode *node = new TreeNode(val);
                        node->right = curr->right;
                        curr->right = node;
                    }
                    else{
                        q.push(curr->right);
                    }
                }
                else{
                   if(count == depth){
                        TreeNode *node = new TreeNode(val);
                        node->right = curr->right;
                        curr->right = node;
                    } 
                }
            }
            count++;
        }
        return root;
    }
};
// PROBLEM:- https://leetcode.com/problems/add-one-row-to-tree/description/
