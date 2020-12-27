// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/280

class Solution {

    void call(TreeNode* r, vector<string> &vs, string res){ // NOTE: very important, not passing the string by reference,                                                                  analyse and re understand.

        // performing the pre order traversal, i.e DLR

        if(r==NULL) return;

        if(!(r->left) && !(r->right)){

            res = res + to_string(r->val);
            vs.push_back(res);
            return;
        }

        res = res + to_string(r->val) + "->";

        call(r->left,vs,res);
        call(r->right,vs,res);

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        if(root == NULL) return {};

        vector<string> vs;

        string res = "";

        call(root,vs,res);

        return vs;
    }
};
