// Problem Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/?track=amazon-trees&batchId=192

void call(Node* root, int dist, int level, map<int,pair<int,int>> &m){

    if(root == NULL) return;

    auto p = m.find(dist);

    if(p == m.end() || level >= m[dist].first){
        m[dist] = {level, root -> data};
    }

    call(root -> left,dist-1,level+1,m);
    call(root -> right,dist+1,level+1,m);
}
vector <int> bottomView(Node *root)
{
   // map: distance - level, node
   map<int,pair<int,int>> m;
   call(root,0,0,m);

   vector<int> vs;
   for(auto itr : m){
       vs.push_back(itr.second.second);
   }
   return vs;
}
