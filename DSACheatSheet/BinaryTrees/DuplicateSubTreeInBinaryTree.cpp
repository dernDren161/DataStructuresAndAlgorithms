// Problem Link: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#

unordered_map<string,int>m;

string callToCompute(Node* r){

     string s=""; // This is important as in each recursive call we perform '+' operation and if s is not null here or not declared then we just cannot do so.

     if(r==NULL) return "%"; // NOTE: important concept

    if(r->left==NULL && r->right==NULL){
        return s=to_string(r->data);
    }

    s += to_string(r->data);
    s += callToCompute(r->left);
    s += callToCompute(r->right);
    m[s]++;

    return s;

}
bool dupSub(Node *root)
{
     //your code here
     m.clear(); // NOTE: Without this the code won't produce the correct result an important lesson
     callToCompute(root);

     for(auto x: m){
         if(x.second > 1) return true;
     }

     return false;
}
