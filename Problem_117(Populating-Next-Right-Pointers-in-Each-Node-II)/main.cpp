/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root){
            q.push(root);
        }
        while(q.size()>0){
            int n = q.size();
            Node *last = NULL;
            while(n--){
                Node *curr = q.front();
                q.pop();
                if(last){
                    last->next = curr;
                }
                last = curr;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
// PROBLEM:- https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description
