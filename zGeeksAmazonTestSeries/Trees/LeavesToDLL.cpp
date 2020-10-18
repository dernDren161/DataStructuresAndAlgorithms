// Problem Link: https://practice.geeksforgeeks.org/problems/leaves-to-dll/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1
// Weird GFG

Node* st = NULL;
Node *convertToDLL(Node *root,Node **head_ref)
{
//add code here.

if(root==NULL) return NULL;

if(root->left==NULL&&root->right==NULL)
{
   if(*head_ref==NULL){
     *head_ref = root;
      st = root;
  }
  else
      {
        st->right = root;
        root->left = st;
        st = root;
      }
}
else
    {
     convertToDLL(root->left,head_ref);
     convertToDLL(root->right,head_ref);
    }
}
