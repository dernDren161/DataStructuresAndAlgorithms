// Problem Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/0/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

void removeLoop(Node* head)
{

   // NOTE: This is a very important base case !!
    if(head == NULL || head->next == NULL) return;

    Node* slow;
    Node* fast;

    slow = head;
    fast = head;

    slow = slow -> next;
    fast = fast -> next -> next;

    // Loop Detection
    while(fast != NULL && fast -> next != NULL){

        if(slow == fast) break;

        slow = slow -> next;
        fast = fast -> next -> next;
    }

    if(slow!=fast) return; // NOTE: There is no loop;
    // Loop Removeal - 1
    // This code is for when the loop directly starts from the last node to the very first node in the LinkedList
    if(slow == head){

      // This is the case when there is no gap in between the slow and fast pointers.

        while(slow -> next != head){
            slow = slow -> next;
        }

        slow -> next = NULL;
    }

    // Loop Removal - 2
    if(slow == fast){
        slow = head;
        while(slow -> next != fast -> next){

            fast = fast -> next;
            slow = slow -> next;
        }

        fast -> next = NULL;
    }
}
