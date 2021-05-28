

void callLeaves(Node* root, int& total){
  if(root){
    callLeftLeaves(root->left,total);
    if(root->left==NULL && root->right==NULL){
      total += root->data;
    }
    callLeftLeaves(root->right,total);
  }
}
void callRightBoundary(Node* root, int& total){
  if(root){
    if(root->right){
      total += root->data;
      callRightBoundary(root->right,total);
    }else if(root->left){
      total += root->data;
      callRightBoundary(root->left,total);
    }
  }
}
void callLeftBoundary(Node* root, int& total){
  if(root){
    if(root->left){
      total += root->data;
      callLeftBoundary(root->left,total);
    }else if(root->right){
      total += root->data;
      callLeftBoundary(root->right,total);
    }
  }
}
int BoundarySumMain(Node* root){

  if(root==NULL) return -1;

  int total = root->data;

  callLeftBoundary(root->left,total);

  callLeaves(root->left,total);
  callLeaves(root->right,total);

  callRightBoundary(root->right,total);

  return total;
}
