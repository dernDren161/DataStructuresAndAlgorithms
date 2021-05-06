// This question was found during the Pramp interview session
// This question was also asked in the Samsung coding round


void find(struct TreeNode* tree, int key, int &ans){
    if(tree==NULL) return;
    if(tree->data<key) find(tree->right, key, ans);
    else{
      if(ans == -1) ans = tree->data;
    else ans = min(ans,tree->data);
    find(tree->left, key,ans);
  }
}

int ceilValue(struct TreeNode* tree, int key){
    if(tree==NULL) return -1;
    int ans = -1;
    find(tree,key,ans);
    return ans;
}

/*
Other things learnt during the coding round.

char* s;
string a(s);

char* temp = strcpy(new char[res.size()],res.c_str());
return temp;
*/
