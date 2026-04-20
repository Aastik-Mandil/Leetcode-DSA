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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ansHead = NULL, *curr = NULL;
        ListNode *curr1 = l1, *curr2 = l2;
        int carry = 0;
        while(carry > 0 || curr1 || curr2){
            int total = carry;
            if(curr1){
                total += curr1->val;
                curr1 = curr1->next;
            }
            if(curr2){
                total += curr2->val;
                curr2 = curr2->next;
            }

            ListNode *node = new ListNode(total%10);
            if(ansHead){
                curr->next = node;
                curr = node;
            }
            else{
                ansHead = node;
                curr = node;
            }
            carry = total/10;
        }
        return ansHead;
    }
};
// PROBLEM:- https://leetcode.com/problems/add-two-numbers/description/
