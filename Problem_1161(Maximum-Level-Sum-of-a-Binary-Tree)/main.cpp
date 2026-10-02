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
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = -1;
        int idx = 0;
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }

        while(q.size() > 0){
            int n = q.size();
            int total = 0;
            if(n > 0){
                while(n--){
                    TreeNode *curr = q.front();
                    q.pop();
                    total += curr->val;
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
                if(maxi < total){
                    maxi = total;
                    ans = idx;
                }
            }
            idx++;
        }
        return ans+1;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description
