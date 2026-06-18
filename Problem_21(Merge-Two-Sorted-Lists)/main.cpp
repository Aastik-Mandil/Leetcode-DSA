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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ansHead = NULL, *ansCurr = NULL;
        ListNode *curr1 = list1, *curr2 = list2;
        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                ListNode *node = new ListNode(curr2->val);
                if(ansHead == NULL){
                    ansHead = node;
                    ansCurr = node;
                }
                else{
                    ansCurr->next = node;
                    ansCurr = node;
                }
                curr2 = curr2->next;
            }
            else{
                ListNode *node = new ListNode(curr1->val);
                if(ansHead == NULL){
                    ansHead = node;
                    ansCurr = node;
                }
                else{
                    ansCurr->next = node;
                    ansCurr = node;
                }
                curr1 = curr1->next;
            }
        }
        while(curr1){
            ListNode *node = new ListNode(curr1->val);
            if(ansHead == NULL){
                ansHead = node;
                ansCurr = node;
            }
            else{
                ansCurr->next = node;
                ansCurr = node;
            }
            curr1 = curr1->next;
        }
        while(curr2){
            ListNode *node = new ListNode(curr2->val);
            if(ansHead == NULL){
                ansHead = node;
                ansCurr = node;
            }
            else{
                ansCurr->next = node;
                ansCurr = node;
            }
            curr2 = curr2->next;
        }
        return ansHead;
    }
};
// PROBLEM:- https://leetcode.com/problems/merge-two-sorted-lists/description/
