// Problem Link: https://www.geeksforgeeks.org/sum-of-all-the-child-nodes-with-even-grandparents-in-a-binary-tree/

call(root,NULL,NULL,0);

void call(Node* root, Node* p, Node* gp, int & s){

  if(root==NULL) return;

  if(gp != NULL && (gp->data)%2==0){
    s += (root->data);
  }

  call(root->left,root,p,s);
  call(root->right,root,p,s);
}
