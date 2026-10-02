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
    unordered_map<TreeNode*, TreeNode*> parent;
    void getAllParent(TreeNode *root, TreeNode* par){
        if(root){
            parent[root] = par;
            getAllParent(root->left, root);
            getAllParent(root->right, root);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getAllParent(root, NULL);

        queue<pair<int, TreeNode*>> q;
        unordered_map<TreeNode*, bool> visited;
        q.push({k, target});
        visited[target] = true;
        vector<int> ans;
        while(q.size()>0){
            int cnt = q.front().first;
            TreeNode *node = q.front().second;
            if(cnt == 0){
                ans.push_back(node->val);
            }
            q.pop();
            if(cnt-1 >= 0 && parent[node] && !visited[parent[node]]){
                q.push({cnt-1, parent[node]});
                visited[parent[node]] = true;
            }
            if(cnt-1 >= 0 && node->left && !visited[node->left]){
                q.push({cnt-1, node->left});
                visited[node->left] = true;
            }
            if(cnt-1 >= 0 && node->right && !visited[node->right]){
                q.push({cnt-1, node->right});
                visited[node->right] = true;
            }
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
