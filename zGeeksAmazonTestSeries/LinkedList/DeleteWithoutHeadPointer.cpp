// Problem Link: https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/?company[]=Amazon&problemStatus=solved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatussolvedproblemTypefunctionalpage1sortBysubmissions

void deleteNode(Node *node)
{
    if(node -> next == NULL){
        node -> data = NULL;
    }

   Node* n;
   n = node -> next;
   Node * en = n -> next;

   node -> data = n -> data;
   node -> next = en;
}
