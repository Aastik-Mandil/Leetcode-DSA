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
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr = head;
        ListNode *head1 = NULL, *curr1 = NULL; // small
        ListNode *head2 = NULL, *curr2 = NULL; // big
        while(curr){
            ListNode *ptr = new ListNode(curr->val);
            if(curr->val < x){
                if(head1){
                    curr1->next = ptr;
                }
                else{
                    head1 = ptr;
                }
                curr1 = ptr;
            }
            else{
                if(head2){
                    curr2->next = ptr;
                }
                else{
                    head2 = ptr;
                }
                curr2 = ptr;
            }
            curr = curr->next;
        }
        if(head1 == NULL){
            return head2;
        }
        if(head1 && head2){
            curr1->next = head2;
        }
        if(head1){
            return head1;
        }
        if(head2){
            return head2;
        }
        return NULL;
    }
};
// PROBLEM:- https://leetcode.com/problems/partition-list/description
