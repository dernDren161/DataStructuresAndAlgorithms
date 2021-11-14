// Problem Link: https://workat.tech/problem-solving/practice/inorder-successor-bst

unordered_map<Node*,Node*>m;
Node* call(Node* r){
	Node* a = r;

	while(a && a->left) a= a->left;

	return a;
}
void callToPopulate(Node* r, Node* par){
	if(r==NULL) return;

	m[r] = par;
	callToPopulate(r->left,r);
	callToPopulate(r->right,r);
}

Node* findSuccessor(Node* root, Node* p) {
    // add your logic here
	if(root==NULL) return NULL;

	callToPopulate(root,NULL);

	if(p->right != NULL){
		return call(p->right);
	}

	Node* par;
	if(p->right == NULL){
		par = m[p];
		while(par && par->right == p){
			p = par;
			par = m[par];
		}
	}

	return par;
}
