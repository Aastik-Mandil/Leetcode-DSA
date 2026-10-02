/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* DFS(Node *node, unordered_map<int, Node*> &mp){
        if(mp[node->val]){
            return mp[node->val];
        }
        Node *curr = new Node(node->val);
        mp[node->val] = curr;
        for(Node* nbr: node->neighbors){
            curr->neighbors.push_back(DFS(nbr, mp));
        }
        return curr;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        unordered_map<int,Node*> mp;
        return DFS(node, mp);
    }
};
// PROBLEM:- https://leetcode.com/problems/clone-graph/description/
