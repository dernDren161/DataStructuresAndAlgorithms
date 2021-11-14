// Problem Link: https://workat.tech/problem-solving/practice/palindromic-partitioning

bool isPalindrome(string s, int l, int r){

	while(l<r){
		if(s[l]==s[r]){
			l++;r--;
		}else return false;
	}

	return true;
}
void call(string s, int l, int r, vector<string> &cur, vector<vector<string>> &whole){

	if(l>=r){
		whole.push_back(cur);
		return;
	}
	for(int i=l;i<r;i++){
		if(isPalindrome(s,l,i)){
			cur.push_back(s.substr(l,i-l+1));
			call(s,i+1,r,cur,whole);
			cur.pop_back();
		}
	}
}
vector<vector<string> > getPartitions(string s) {
    // add logic here
	int n = s.size();
	if(n==0) return {};

	vector<string>cur;
	vector<vector<string>>whole;

	call(s,0,n,cur,whole);

	return whole;
}
