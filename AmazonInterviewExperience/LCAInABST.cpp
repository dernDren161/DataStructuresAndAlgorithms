// Problem Link: https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
// T.C: O(h), where h is the height of the tree
// S.C: If the recursion stack is considered then, O(h)

Node* lca(Node* root, int n1, int n2){

  if(root==NULL) return NULL;

  if(root->data > n1 && root->data > n2){
    return lca(root->left,n1,n2);
  }

  if(root->data < n1 && root->data < n2){
    return lca(root->right,n1,n2);
  }

  return root;
}
