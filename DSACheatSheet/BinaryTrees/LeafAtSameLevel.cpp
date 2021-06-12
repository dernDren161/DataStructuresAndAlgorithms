// Problem Link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

class Solution{
  public:
    /*You are required to complete this method*/

    bool callToCheck(Node* root, int level, int &leafLevel){

        if(root==NULL) return true;

        if(root->left==NULL && root->right==NULL){

            if(leafLevel==0){
                leafLevel = level;
                return true;
            }

            return (level==leafLevel);
        }

        return callToCheck(root->left,level+1,leafLevel)&& callToCheck(root->right,level+1,leafLevel);
    }

    bool check(Node *root)
    {
        //Your code here
        int level  = 0;
        int leafLevel = 0;

        return callToCheck(root,level,leafLevel);
    }
};
