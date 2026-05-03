/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "N";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        if(data[0] == 'N'){
            return NULL;
        }

        int num = 0;
        bool pos = true;
        unordered_map<TreeNode*, int> mp;
        stack<TreeNode*> q;
        TreeNode *root = NULL;
        for(int i=0 ;i<data.size(); i++){
            char ch = data[i];
            if(ch == '-'){
                pos = false;
            }
            else if(ch == 'N'){
                if(q.size() > 0 && mp[q.top()] == 1){
                    mp[q.top()] = 2;
                    i++;
                }
                else if(q.size() > 0 && mp[q.top()] == 2){
                    mp.erase(q.top());
                    q.pop();
                    i++;
                }
                num = 0;
                pos = true;
            }
            else if(ch == ','){
                TreeNode *node = new TreeNode(pos ? num : 0-num);
                if(q.size() > 0 && mp[q.top()] == 1){
                    q.top()->left = node;
                    mp[q.top()] = 2;
                }
                else if(q.size() > 0 && mp[q.top()] == 2){
                    q.top()->right = node;
                    mp.erase(q.top());
                    q.pop();
                }
                q.push(node);
                mp[node] = 1;
                num = 0;
                pos = true;
            }
            else{
                num = (10*num) + (ch-'0');
            }

            if(q.size() == 1 && root == NULL){
                root = q.top();
            }
        }
        TreeNode *node = new TreeNode(pos ? num : 0-num);
        q.push(node);
        if(q.size() == 1 && root == NULL){
            return node;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// PROBLEM:- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
