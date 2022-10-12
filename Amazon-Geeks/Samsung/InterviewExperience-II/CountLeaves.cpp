// Problem Link; https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

void callCount(Node* root, int &c){

    if(root->left==NULL && root->right==NULL){
        c++;
        return;
    }

    if(root->left) callCount(root->left,c);
    if(root->right) callCount(root->right,c);

    return;
}

int countLeaves(Node* root)
{
  // Your code here

  int c = 0;
  callCount(root,c);

  return c;
}
