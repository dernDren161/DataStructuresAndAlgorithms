// Problem Link:
//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/?track=amazon-bst&batchId=192

// This is basically Reverse Morris Traversal.
// Just replace left with right and vice-versa.

// if we do so, then instead of sorted we get the reverse order.

Node* call(Node* root,int k){

    Node* curr;
    Node* pre;
    Node* ans = NULL;
    curr = root;
    int count = 0;
    while(curr != NULL){
        if(curr -> right == NULL){
          if(++count == k) ans = curr;
        curr = curr -> left;
    }
    else{
        pre = curr -> right;
        while((pre -> left != NULL) && (pre -> left != curr)) pre = pre -> left;

        if(pre -> left == NULL){
            pre -> left = curr;
            curr = curr -> right;
        }
        else{
            pre -> left = NULL;
            if(++count == k) ans = curr;
            curr = curr -> left;
        }
    }
    }
    return ans;
}
int kthLargest(Node *root, int K)
{

    return call(root,K) -> data ;

}
