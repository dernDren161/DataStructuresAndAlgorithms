// Problem Link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
// T.C : O(min(m,n)), where m and n are the respective nodes of the two trees

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.

    if(!root1 && !root2) return true;

    if(root1 && root2 && (root1->data==root2->data)){
        return ((isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left))||(isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)));
    }

    return false;
    }
};

/* NOTE:
Case 1: To find the symmetricity of a Tree{
      return call(r1->left,r2->right)&&(r1->right,r2->left);
}
Case 2: To find if the two trees are equal/identical or not{
      return call(r1->left,r2->left)&& call(r1->right,r2->right);
}
Case 3: To find if a Tree is isomorphic or not,(NOTE: Two identical trees are also isomorphic)
      return Case 1 || Case 2;

*/
