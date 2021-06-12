// Problem Link: https://practice.geeksforgeeks.org/problems/sum-tree/1
// Time COmplexity: O(n)

class Solution
{
    public:

    bool isLeaf(Node* root){
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }

    bool checkCall(Node* root){

        int ls;
        int rs;

        if(root == NULL || isLeaf(root)) return true;

        if(checkCall(root->left) && checkCall(root->right)){

            if(root->left == NULL) ls = 0;
            else if(isLeaf(root->left)) ls = root->left->data;
            else ls = 2 * (root->left->data);

            if(root->right == NULL) rs = 0;
            else if(isLeaf(root->right)) rs = root->right->data;
            else rs = 2 * (root->right->data);

            return (root->data == ls+rs);
        }

        return false;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return checkCall(root);
    }
};
