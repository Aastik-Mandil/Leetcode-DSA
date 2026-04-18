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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head;

        ListNode *prev = NULL;
        for(int i=1;i<left;i++){
            prev = curr;
            curr = curr->next;
        }

        ListNode *next = head;
        for(int i=0;i<right;i++){
            next = next->next;
        }

        ListNode *temp = curr;

        ListNode *p = NULL, *n = NULL;
        while(curr != next){
            n = curr->next;
            curr->next = p;
            p = curr;
            curr = n;
        }

        if(prev){
            prev->next = p;
        }
        temp->next = next;

        if(left == 1){
            return p;
        }
        return head;
    }
};
// PROBLEM:- https://leetcode.com/problems/reverse-linked-list-ii/description/
