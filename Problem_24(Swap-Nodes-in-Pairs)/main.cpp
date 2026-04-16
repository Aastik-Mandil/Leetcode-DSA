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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode *prev = NULL, *curr = head, *next = NULL;
        if(curr->next == NULL){
            return head;
        }
        while(curr && curr->next){
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            if(prev){
                prev->next = next;
            }
            if(head == curr){
                head = next;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
// PROBLEM:- https://leetcode.com/problems/swap-nodes-in-pairs/description/
