/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode *node = head;
        while(node){
            pq.push(node->val);
            node = node->next;
        }
        node = head;
        while(pq.size()>0){
            node->val = pq.top();
            pq.pop();
            node = node->next;
        }
        return head;
    }
};
// PROBLEM:- https://leetcode.com/problems/sort-list/description
