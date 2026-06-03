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
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }

        int ans = 0;
        curr = head;
        while(st.size()>0){
            ans=max(ans, st.top()->val+curr->val);
            st.pop();
            curr = curr->next;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description
