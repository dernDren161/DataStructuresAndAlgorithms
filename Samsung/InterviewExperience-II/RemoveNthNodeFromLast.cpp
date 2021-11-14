// Problem Link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp;

        n--;

        while(n){
            fast = fast -> next;
            n--;
        }

        while(fast->next != NULL){
            temp = slow;
            slow = slow -> next;
            fast = fast->next;
        }

        if(slow==head) return head->next;

        temp->next = slow->next;

        return head;
    }
};
