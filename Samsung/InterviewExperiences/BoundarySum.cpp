

void callLeaves(Node* root, int& total){
  if(root){
    callLeaves(root->left,total);
    if(root->left==NULL && root->right==NULL){
      total += root->data;
    }
    callLeaves(root->right,total);
  }
}
void callRightBoundary(Node* root, int& total){
  if(root){
    if(root->right){
      callRightBoundary(root->right,total);   // NOTE: This part is important first go the rightmost non-leaf and then start printing upwards.
      total += root->data;
    }else if(root->left){
      callRightBoundary(root->left,total);
      total += root->data;
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
