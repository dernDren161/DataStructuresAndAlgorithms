// A functional code to construct a Post Order tree from the given Inorder and Pre order tree

// Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1/?track=amazon-trees&batchId=192

int call(int in[], int x, int n){
    for(int i = 0;i<n;i++){
        if(in[i] == x) return i;
    }
    return -1;
}

Node* buildTree(int in[],int pre[], int n)
{
  if(n == 0) return NULL;

   int root = call(in,pre[0],n);

   Node* res = new Node(pre[0]);


   res -> left = buildTree(in,pre+1,root);
   res -> right = buildTree(in+root+1,pre+root+1,n-root-1);
   return res;

}
