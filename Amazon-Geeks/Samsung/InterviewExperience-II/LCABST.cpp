// Problem Link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

// BOTH T.C and S.C are O(h), where 'h' is the height of the Bianry Search Tree

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(n1>root->data && n2>root->data){
      return LCA(root->right,n1,n2);
   }

   if(n1<root->data && n2<root->data){
        return LCA(root->left,n1,n2);
   }

   return root;
}
