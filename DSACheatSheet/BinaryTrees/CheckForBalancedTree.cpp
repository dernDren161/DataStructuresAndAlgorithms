// Problem Link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

int callForHeight(Node* r){
    if(r==NULL) return 0;

    return 1+max(callForHeight(r->right),callForHeight(r->left));
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL) return true;

    int l = callForHeight(root->left);
    int r = callForHeight(root->right);

    if(abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;

    return false;

}
