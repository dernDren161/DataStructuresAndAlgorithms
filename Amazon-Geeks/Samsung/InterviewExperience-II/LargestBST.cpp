// Problem Link: https://practice.geeksforgeeks.org/problems/largest-bst/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=2&query=company[]SamsungproblemStatusunsolvedpage2company[]Samsung

class Solution{
    public:

    vector<int> call(Node* r){
        if(r==NULL){
            return {1,0,INT_MAX,INT_MIN};
        }
        if(r->left==NULL && r->right==NULL){
            return {1,1,r->data,r->data};
        }

        vector<int> le = call(r->left);
        vector<int> ri = call(r->right);

        if(le[0] && ri[0]){
            if(r->data > le[3] && r->data <ri[2]){
                int x = le[2];//min
                int y = ri[3];//max
                if(x==INT_MAX) x = r->data;
                if(y==INT_MIN) y = r->data;

                return {1,le[1]+ri[1]+1,x,y};
            }
        }

        return {0,max(le[1],ri[1]),0,0};
    }

    int largestBst(Node *root)
    {
        // isBST, largest, minimum, maximum
    	vector<int> res = call(root);
    	return res[1];
     }
};
