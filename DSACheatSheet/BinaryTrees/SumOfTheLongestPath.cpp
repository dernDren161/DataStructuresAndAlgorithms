// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

class Solution
{
public:
    int globalSum = INT_MIN;
    int globalLen = 0;

    void call(Node* root, int len, int sum){

        if(root==NULL){
            if(len>globalLen){
                globalSum = sum;
                globalLen = len;
            }else if(len==globalLen && sum > globalSum){
                globalSum = sum;
            }
            return;  // NOTE: Though the return type is void this 'return' statement is necessary
        }

        call(root->left,len+1,sum+root->data);
        call(root->right,len+1,sum+root->data);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        call(root,0,0);

        return globalSum;
    }
};
