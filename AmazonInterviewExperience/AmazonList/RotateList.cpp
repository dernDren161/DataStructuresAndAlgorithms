// Problem Link: https://leetcode.com/problems/rotate-list/solution/
// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || k==0) return head;


        int c = 0;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr->next){
            c++;
            curr = curr->next;
        }

        c++;

        if(k==c) return head;

        curr -> next = head; // making a circular ring



        if(k>c)k = k % c;

        int temp = c - k;

        while(temp--){
            prev = head;
            head = head->next;
        }
        prev->next = NULL;

        return head;
    }
};
