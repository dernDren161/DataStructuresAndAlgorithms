// Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// NOTE: This is basically the Tree variation of the problem 'Social Networking Graph' in the HackerEarth section of Graphs.
// These are some important questions for the understanding of the 'Breadth First Search' agorithm.

class Solution {

    // Key-current node, Value-parent node
    unordered_map<TreeNode*, TreeNode*> m;

    void callToPopulate(TreeNode* root, TreeNode* parent){

        if(root == NULL) return;

        m[root] = parent;
        callToPopulate(root->left,root);
        callToPopulate(root->right,root);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(root==NULL) return {};

        callToPopulate(root,NULL);

        // Run a Simple BFS

        queue<TreeNode*> q;
        q.push(target);

        // NOTE: The use of this set is absolutely nexessary to avoid duplication in printing similar to that of 'bool truth[]'
        unordered_set<TreeNode*>s;
        s.insert(target);

        while(k--){
            int x = q.size();

            for(int i=0;i<x;i++){

                /*NOTE: Very important
                        In Tree BFS, notice that front() and the pop() operation is done inside the for loop
                        Unlike the graph where we do such stuffs "OUTSIDE" the for loop.
                        Because in Graphs we know how many nodes are connected to a node beforehand
                        But in the case of trees we need to explore hence these operations are done inside the for loop in the case of Trees.
                */

                TreeNode* f = q.front();
                q.pop();

                if(f->left && s.find(f->left)==s.end()){
                    q.push(f->left);
                    s.insert(f->left);
                }

                if(f->right && s.find(f->right)==s.end()){
                    q.push(f->right);
                    s.insert(f->right);
                }

                if(m[f]!=NULL && s.find(m[f])==s.end()){
                    q.push(m[f]);
                    s.insert(m[f]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
