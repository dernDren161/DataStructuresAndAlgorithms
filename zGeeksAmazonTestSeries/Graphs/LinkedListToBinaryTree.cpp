// Problem Link: https://practice.geeksforgeeks.org/problems/make-binary-tree/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// This code does not work but the concept is correct, just learn the concepts.

void convert(Node *head, TreeNode *&root) {

   if(head == NULL){
       root = NULL;
       return;
   }

   queue<Node*> qs;
   qs.push(head);
   head = head -> next;

   while(head){

      Node* t = qs.front();

      TreeNode* temp;

      temp -> data = t -> data;

      qs.pop();

      Node* l = head;

      qs.push(l);

      Node* r;

      head = head -> next;

      if(head){
          r = head;
          qs.push(r);
          head = head -> next;
      }

      temp -> left -> data= l -> data;
      temp -> right -> data= r -> data;
   }

}
