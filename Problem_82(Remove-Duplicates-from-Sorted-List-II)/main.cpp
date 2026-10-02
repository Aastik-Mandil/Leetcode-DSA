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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode *curr = head;
        while(curr){
            mp[curr->val]++;
            curr = curr->next;
        }

        ListNode *head1 = NULL, *ptr = NULL;
        curr = head;
        while(curr){
            if(mp[curr->val] == 1){
                ListNode *temp = new ListNode(curr->val);
                if(head1){
                    ptr->next = temp;
                }
                else{
                    head1 = temp;
                }
                ptr = temp;
            }
            curr = curr->next;
        }
        return head1;
    }
};
// PROBLEM:- https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description
