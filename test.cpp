TreeNode * getAns(TreeNode *root)
{
if(root==NULL)
return root;

    TreeNode *left=NULL,*right=NULL;

    left=getAns(root->left);
    right=getAns(root->right);

    if(left==NULL)
        left=root;

    left->left=root->right;
    root->right=NULL;

    if(right==NULL)
        return left;
    return right;
}

void leftToRight(TreeNode *root)
{
    if(root==NULL)
        return;
    leftToRight(root->left);
    root->right=root->left;
    root->left=NULL;
}

void flatten(TreeNode* root)
{
    getAns(root);
    leftToRight(root);
}
