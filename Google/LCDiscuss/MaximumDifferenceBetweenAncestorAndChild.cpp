// Discuss Link: https://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/

int maxDiffUtil(Node* t, int *res)
{
    /* Returning Maximum int value if node is not
       there (one child case)  */
    if (t == NULL)
        return INT_MAX;

    /* If leaf node then just return node's value  */
    if (t->left == NULL && t->right == NULL)
        return t->key;

    /* Recursively calling left and right subtree
       for minimum value  */
    int val = min(maxDiffUtil(t->left, res),
                  maxDiffUtil(t->right, res));

    /* Updating res if (node value - minimum value
       from subtree) is bigger than res  */
    *res = max(*res, t->key - val);

    /* Returning minimum value got so far */
    return min(val, t->key);
}
