// Problem Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/?track=amazon-trees&batchId=192


// always do a post-traversal in such questions.

int call(Node* root, int count){
    if(root == NULL){
        int temp = count;
        count = 0;
        return temp;
    }
    int left = call(root -> left, count+1);
    int right = call(root -> right, count+1);

    return max(left,right);
}


int height(Node* root)
{
   // Your code here
   int count = 0;
    return call(root,count);
}
