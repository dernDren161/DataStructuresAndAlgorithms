// Problem Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

class Solution{
    public:
    //Function to find the height of a binary tree.
    int call(Node* node, int ht){
    if(node==NULL){
        int x = ht;  // NOTE: Here when node->left was equal to NULL, then also we increse ht, because we here consider the root node.
        ht = 0;
        return x;
    }

   int l = call(node->left,ht+1);
   int r = call(node->right,ht+1);

   int temp = max(l,r);

   return temp;

}
int height(struct Node* node)
{
    //code here
    int ht = 0;

    return call(node,ht);
}
};
