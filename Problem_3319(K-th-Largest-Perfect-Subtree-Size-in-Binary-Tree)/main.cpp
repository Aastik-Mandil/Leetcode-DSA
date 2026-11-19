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
    vector<pair<int, TreeNode*>> v;

    // traverse root and get its height
    int traverse(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int l = traverse(root->left);
        int r = traverse(root->right);
        if(l != -1 && r != -1 && l == r){
            v.push_back({l+1, root});
            return l + 1;
        }
        return -1;
    }

    // count the node
    int count(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        v.clear();

        traverse(root);

        // sort based on count
        sort(v.begin(), v.end(), [](pair<int, TreeNode*> &a, pair<int, TreeNode*> &b){
            return a.first > b.first;
        });

        if(k > v.size()){
            return -1;
        }
        return count(v[k-1].second);
    }
};
// PROBLEM:- https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/
