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
struct CustomCompare {
    bool operator()(ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CustomCompare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }

        ListNode *head = NULL, *curr = NULL;
        while(pq.size()>0){
            ListNode *top = pq.top();
            pq.pop();
            if(top->next){
                pq.push(top->next);
            }
            if(head){
                curr->next = top;
            }
            else{
                head = top;
            }
            curr = top;
        }
        return head;
    }
};
// PROBLEM:- https://leetcode.com/problems/merge-k-sorted-lists/description
