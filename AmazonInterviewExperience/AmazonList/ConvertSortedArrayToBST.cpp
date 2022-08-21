// Problem Link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/
// It creates height balanced BST

// SImilar technique in three questions : From Inorder, Quick Sort and Convert array to BST.

class Solution {
public:
    TreeNode* call(vector<int>&nums, int l, int r){

        if(l>r) return NULL;

        int m = (l+r)/2;

        TreeNode* node = new TreeNode(nums[m]);
        node->left = call(nums,l,m-1);
        node->right = call(nums,m+1,r);

        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if(nums.size()==0) return NULL;

        return call(nums,0,nums.size()-1);
    }
};
