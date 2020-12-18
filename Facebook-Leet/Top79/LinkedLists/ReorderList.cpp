// Problem Link: https://leetcode.com/explore/interview/card/facebook/6/linked-list/3021


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
    void reorderList(ListNode* head) {
        /*
        Given 1->2->3->4,
        reorder it to 1->4->2->3.
        */

        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        fast = fast -> next;

        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // slow is the middle point.
        ListNode* h2 = slow -> next;
        slow -> next = NULL;
        ListNode* h1 = head;

        // now reverse the second half of the linked list
        // for h2

        ListNode* pre = NULL;
        ListNode* ne = NULL;
        ListNode* cur;
        cur = h2;

        while(cur){
            ne = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = ne;
        }
        h2 = pre;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy; // dummy is always right

        while(h1!=NULL || h2!=NULL){

            if(h1!=NULL){
                temp -> next = h1;
                temp = temp -> next;
                h1 = h1->next;
            }

            if(h2!=NULL){
                temp -> next = h2;
                temp = temp -> next;
                h2 = h2 -> next;
            }
        }

        head = dummy->next;
    }
};
