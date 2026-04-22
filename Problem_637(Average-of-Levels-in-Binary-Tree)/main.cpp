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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        vector<double> ans;
        while(q.size() > 0){
            int n = q.size();
            long long total = 0, count = n;
            while(n--){
                TreeNode *node = q.front();
                q.pop();
                total += (node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(count>0){
                ans.push_back((total*1.00000) / count);
            }
        }
        return ans;
    }
};
// PROBLEM: https://leetcode.com/problems/average-of-levels-in-binary-tree/description
