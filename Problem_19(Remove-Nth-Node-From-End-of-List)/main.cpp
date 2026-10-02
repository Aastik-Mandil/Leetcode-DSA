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
    int getLength(ListNode *head){
        ListNode *curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getLength(head);
        if(size==n){
            return head->next;
        }
        if(size < n){
            return head;
        }
        int count = size - n;
        ListNode *curr = head;
        for(int i=1;i<count;i++){
            curr=curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};
// PROBLEM:- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
