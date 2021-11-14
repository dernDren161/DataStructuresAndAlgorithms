// Problem Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/*
  To find the middle element it takes: O(n/2) time or steps
  To traverse the BST it would take: O(log n) time

  // NOTE: UIsually if there is BST, the T.C is always O(log n), remember that's why we use Trie
  T.C: O(n logn)
  S.C: O(log n)
*/

class Solution {
public:

    ListNode* callToMid(ListNode* l, ListNode* r){

        ListNode* slow = l;
        ListNode* fast = l;

        while(fast && fast!=r && fast->next!=r){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    TreeNode* callToCompute(ListNode* l, ListNode* r, TreeNode* root){

        if(l==r) return root;

        ListNode* middle = callToMid(l,r);

        if(root==NULL){
            root = new TreeNode(middle->val);
        }
        root->left = callToCompute(l,middle,root->left);
        root->right = callToCompute(middle->next,r,root->right);

        return root; // NOTE: important case
    }
    TreeNode* sortedListToBST(ListNode* head) {

        return callToCompute(head,NULL,NULL);
    }
};
