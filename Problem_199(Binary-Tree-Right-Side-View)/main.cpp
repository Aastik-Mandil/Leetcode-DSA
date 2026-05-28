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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int idx = 0;
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }

        while(q.size() > 0){
            int n = q.size();
            if(n > 0){
                ans.push_back(-1);
            }
            idx++;
            while(n--){
                TreeNode *curr = q.front();
                q.pop();
                ans[ans.size() - 1] = curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/binary-tree-right-side-view/description
