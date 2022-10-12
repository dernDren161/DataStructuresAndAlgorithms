// Problem Link: https://workat.tech/problem-solving/practice/inorder-successor-bst
// Algo Link: https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/

unordered_map<Node*,Node*>m; // current node, parent node

void callToPopulate(Node* cur, Node* parent){
	if(cur==NULL) return;

	m[cur] = parent;
	callToPopulate(cur->left,cur);
	callToPopulate(cur->right,cur);
}

Node* callToFind(Node* r){

	Node* a = r;

	while(a && a->left){
		a = a->left;
	}

	return a;
}

Node* findSuccessor(Node* root, Node* p) {

	if(root==NULL) return NULL;

	callToPopulate(root,NULL);

	// if the right one is not NULL
	if(p->right != NULL){
		return callToFind(p->right);
	}

	// if the right node is NULL
	Node* par;
	if(p->right==NULL){
		par = m[p]; // par is p's parent
		while(par && par->right==p){
			p = par;
			par = m[p];
		}
	}

	return par;

}
