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
    ListNode* solve1(ListNode* head){
        ListNode *headEven = NULL, *currEven = NULL;
        ListNode *headOdd = NULL, *currOdd = NULL;
        ListNode *curr = head;
        bool flag = true;
        while(curr){
            ListNode *node = new ListNode(curr->val);
            if(flag){
                if(headEven){
                    currEven->next = node;
                }
                else{
                    headEven = node;
                }
                currEven = node;
            }
            else{
                if(headOdd){
                    currOdd->next = node;
                }
                else{
                    headOdd = node;
                }
                currOdd = node;
            }
            flag = !flag;
            curr = curr->next;
        }
        currEven->next = headOdd;
        return headEven;
    }
    ListNode* solve2(ListNode* head){
        ListNode *ptr = head->next;
        ListNode *even = head, *odd = head->next;
        bool flag = true;
        while(even && odd){
            if(flag){
                even->next = odd->next;
                if(even->next){
                    even = even->next;
                }
                else{
                    break;
                }
            }
            else{
                odd->next = even->next;
                if(odd->next){
                    odd = odd->next;
                }
                else{
                    break;
                }
            }
            flag = !flag;
        }
        if(even){
            even->next = ptr;
        }
        return head;
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        // return solve1(head);

        return solve2(head);
    }
};
// PROBLEM:- https://leetcode.com/problems/odd-even-linked-list/description
