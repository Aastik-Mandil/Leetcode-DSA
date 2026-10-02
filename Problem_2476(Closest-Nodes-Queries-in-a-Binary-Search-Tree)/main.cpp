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
    vector<int> v;

    void traverse(TreeNode *root){
        if(root == NULL){
            return;
        }
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    vector<int> findSmall(int val){
        // cout<<val<<" -> "<<endl;
        int l = 1, r = v.size()-2;
        // int ans = -1;
        while(l <= r){
            int mid = l + ((r - l) / 2);
            // cout<<l<<" , "<<r<<" - "<<mid<<endl;
            if(v[mid] == val){
                // cout<<mid<<endl;
                return {v[mid], v[mid]};
            }
            else if(v[mid] > val){
                r = mid-1;
            }
            else{
                // ans = mid;
                l = mid+1;
            }
        }
        // cout<<l<<" , "<<r<<endl;
        return {v[r], v[l]};
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        v.clear();
        v.push_back(-1);
        traverse(root);
        v.push_back(-1);

        vector<vector<int>> ans;
        for(int query: queries){
            ans.push_back(findSmall(query));
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/
