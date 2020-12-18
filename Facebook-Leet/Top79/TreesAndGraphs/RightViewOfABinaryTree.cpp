// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/3023

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 1,n,2,3,n,5,4,n

        // ...... n,3,2,n,1

        vector<int> vs;
        vs.clear();

        if(root == NULL){
            return {};
        }

        if(root->left==NULL && root->right==NULL){
            vs.push_back(root->val);
            return vs;
        }

       queue<TreeNode*> qs;
       qs.push(root);
       qs.push(NULL);

       TreeNode* temp;
       TreeNode* f;

        // 1,n,2,3,n,5,4,n

        // ...... n,3,2,n,1

        while(qs.size() > 1){

            f = qs.front();
            qs.pop();

            if(f == NULL){
                vs.push_back(temp->val);
                qs.push(NULL);
            }else{
                if(f->left){
                    qs.push(f->left);
                }

                if(f->right){
                   qs.push(f->right);
                }
            }
            temp = f;
        }

       vs.push_back(temp->val);

        return vs;
    }
};
