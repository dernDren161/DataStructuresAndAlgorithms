// Problem Link: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions
// Based on Floyd's hare and tortoise algorithm.

bool detectLoop(Node* head)
{

   // This should be a common code check for all the Linked List problems
    if(head == NULL || head -> next == NULL) return false;

    Node* slow;
    Node* fast;


    slow = head;
    fast = head;

    slow = slow -> next;
    fast = fast -> next -> next;

    /*
    Can also write:

    slow = head;
    fast = fast -> next;

    ... Just that fast should be one step ahead to slow while starting off.
    */

    while(fast && fast -> next){

        if(fast == slow) break;

        slow = slow -> next;
        fast = fast -> next -> next;
    }

    if(fast == slow) return true;

    return false;

}
