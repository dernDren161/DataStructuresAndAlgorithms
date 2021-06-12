// Problem Link: https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

// NOTE: This is the memoization approach to solve this Problem
// The time complexity here is: O(N), as it visits each node once
// Whereas the space complexity is, O(N)

unordered_map<Node*,int> dp; // Node and the sum till that Node

int func(Node* root){

    if(root==NULL) return 0;

    if(dp[root]) return dp[root];

    // If I take the root node, then
    int take = root->data;

    if(root->left){
      take += func(root->left->left);
      take += func(root->left->right);
    }

    if(root->right){
      take += func(root->right->left);
      take += func(root->right->right);
    }

    // When I don't take the root node then,
    int notTake = func(root->left) + func(root->right);

    dp[root] = max(take,notTake);

    return dp[root];
}
