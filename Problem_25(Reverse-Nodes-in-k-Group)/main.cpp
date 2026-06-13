x/**
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        vector<ListNode*> v;
        ListNode *curr = head;
        while(curr){
            v.push_back(curr);
            curr = curr->next;
            v.back()->next = NULL;
        }
        for(int i=0; i<v.size(); i+=k){
            int st = i, ed = i+k-1;
            if(ed>=v.size()){
                break;
            }
            while(st<ed){
                ListNode *temp = v[st];
                v[st] = v[ed];
                v[ed] = temp;
                st++;
                ed--;
            }
        }

        for(int i=1; i<v.size(); i++){
            v[i-1]->next = v[i];
        }
        return v[0];
    }
};
// PROBLEM:- https://leetcode.com/problems/reverse-nodes-in-k-group/description
