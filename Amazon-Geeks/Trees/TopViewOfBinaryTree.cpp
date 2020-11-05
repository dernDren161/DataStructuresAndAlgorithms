// Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// pre order traversal.-- because the node display is from Left to Right.

void call(Node* root, int dist, int level, map<int,pair<int,int>> &m){

    if(root == NULL) return;

    auto p = m.find(dist);

    if(p == m.end() || (level < (m[dist].first))){
        m[dist] = {level,root -> data};
    }
    call(root -> left,dist-1,level+1,m);
    call(root -> right,dist+1,level+1,m);
}

void topView(struct Node *root)
{
    // distance - level,node
   map<int,pair<int,int>> m;
   m.clear();
   call(root,0,0,m);

   for(auto itr : m){
       cout << itr.second.second << " ";
   }
}
