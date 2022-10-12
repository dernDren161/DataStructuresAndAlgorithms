
int call(Node* root){

    if(root == NULL) return 0;

    int l = call(root->left);
    int r = call(root->right);

    int oldValue = root -> data;

    root->data = l + r;

    return (root->data + oldValue);
}

Node* sumTree(Node* root){

  if(root==NULL) return NULL;
  if(root->left== NULL && root->right==NULL) return root;

  call(root);
}
