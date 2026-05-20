/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        mp.clear();
        Node *curr = head;
        Node *ansHead = NULL, *ansCurr = NULL;
        while(curr){
            Node *ptr = new Node(curr->val);
            mp[curr] = ptr;
            if(ansHead){
                ansCurr->next = ptr;
            }
            else{
                ansHead = ptr;
            }
            ansCurr = ptr;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node *random = curr->random;
            if(random){
                mp[curr]->random = mp[random];
            }
            else{
                mp[curr]->random = NULL;
            }
            curr = curr->next;
        }
        return ansHead;
    }
};
// PROBLEM:- https://leetcode.com/problems/copy-list-with-random-pointer/description
