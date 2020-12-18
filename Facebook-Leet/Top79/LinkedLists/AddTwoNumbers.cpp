// Problem Link: https://leetcode.com/explore/interview/card/facebook/6/linked-list/319/

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

        /*
        Input: l1 = [2,4,3], l2 = [5,6,4]
        Output: [7,0,8]
        Explanation: 342 + 465 = 807.
        */

        ListNode* dummy = new ListNode();
        ListNode* head;
        head = dummy;   // NOTE: The 'dummy is always right'  X-D

        int s = 0;
        int carry = 0;

        while(l1 != NULL || l2!=NULL){

            s = carry;

            if(l1 != NULL){
                s += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                s+=l2->val;
                l2 = l2->next;
            }

            ListNode* x = new ListNode(s%10);
            dummy -> next = x;
            dummy = dummy->next;
            carry = s / 10;
        }

        if(carry!=0){
            ListNode* final = new ListNode(carry);
            dummy -> next = final;
            final -> next = NULL;
        }

        return head -> next;
    }
};
