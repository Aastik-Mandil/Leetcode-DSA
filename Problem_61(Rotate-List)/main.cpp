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
    int count(ListNode* head){
        ListNode *node = head;
        int cnt = 0;
        while(node){
            cnt++;
            node = node->next;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){
            return head;
        }

        int total = count(head);
        if(total == 0){
            return head;
        }

        k%=total;
        total-=k;

        ListNode *curr = head, *last = NULL;
        while(total>0){
            last = curr;
            curr = curr->next;
            total--;
        }
        ListNode *ansHead = curr;
        while(curr && curr->next){
            curr = curr->next;
        }
        if(curr == NULL){
            return head;
        }

        curr->next = head;
        last->next = NULL;
        return ansHead;
    }
}
// PROBLEM:- https://leetcode.com/problems/rotate-list/description/
