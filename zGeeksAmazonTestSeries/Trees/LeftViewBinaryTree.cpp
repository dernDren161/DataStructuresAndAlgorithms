// Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/?track=amazon-trees&batchId=192

void call(Node* root){

    if(root == NULL) return;

    queue<Node*> qs;
    qs.push(root);
    qs.push(NULL);

    Node* cur;
    Node* temp;

    while(qs.size() > 1){

        cur = qs.front();
        qs.pop();

        if(cur == NULL){
            qs.push(NULL);
            cout << temp -> data << " ";
        }
        else{
          // for left view, first push ---> right pointer
            if(cur -> right) qs.push(cur -> right);
            if(cur -> left) qs.push(cur -> left);
        }

        temp = cur;
    }

    cout << temp -> data << " ";
}

void leftView(Node *root)
{
   call(root);
}
