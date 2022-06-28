// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/submissions/
// T.C: O(nlogk)
// S.C: O(k)

class Solution {
public:

    struct comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();


        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        for(int i=0;i<k;i++){
           if(lists[i]) pq.push(lists[i]);  // NOTE: If it is empty, do not push cause our sorted list will stop middle way.
        }

        ListNode* temp = new ListNode(-100);
        ListNode* dummy = temp;

        while(!pq.empty()){
            ListNode* t = pq.top();
            pq.pop();

            temp -> next = t;
            temp = temp -> next;

            if(t->next){
                pq.push(t->next);
            }
        }

        return dummy->next;
    }
};
