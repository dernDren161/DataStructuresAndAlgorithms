
Node* call(Node* root, int k){

  if(root == NULL) return NULL;

  root->left = call(root->left,k-root->data);
  root->right = call(root->right,k-root->data);

  if(root->left==NULL && root->right==NULL){
    if(root->data < k){
      free(root);
      return NULL;
    }
  }

  return root;
}
