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
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        int ans=0;
        int cnt = 0;
        ListNode *curr = head;
        while(curr){
            if(curr->val == 1){
                ans+=pow(2, cnt);
            }
            cnt++;
            curr = curr->next;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
