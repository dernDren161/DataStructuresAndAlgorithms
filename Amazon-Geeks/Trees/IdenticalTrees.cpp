// Problem Link: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

void call1(Node* r1, vector<int> &v1){

    // in order traversal - LDR

    if(r1 == NULL) return;

    call1(r1 -> left, v1);
    v1.push_back(r1 -> data);
    call1(r1 -> right, v1);
}

void call2(Node* r1, vector<int> &v2){

    // in order traversal - LDR

    if(r1 == NULL) return;

    call1(r1 -> left, v2);
    v2.push_back(r1 -> data);
    call1(r1 -> right, v2);
}

bool isIdentical(Node *r1, Node *r2)
{

    vector<int> v1;
    v1.clear();

    call1(r1,v1);

    vector<int> v2;
    v2.clear();

    call2(r2,v2);

    if(v1 == v2) return true;

    else return false;
}
