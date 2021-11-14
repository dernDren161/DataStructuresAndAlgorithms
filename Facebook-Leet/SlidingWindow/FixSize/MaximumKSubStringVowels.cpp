// Problem Link: https://workat.tech/problem-solving/practice/maximum-k-substring-vowels

int maxKSubstringVowels(string s, int k) {

	int n = s.size();
	int ma = 0;
	unordered_map<char,int>m;
	m['a']++; m['e']++; m['i']++; m['o']++; m['u'];

	int i; int j; i = 0; j=0;
	int c = 0;

	while(j<n){
		if(m.find(s[j])!=m.end())c++;

		if(j-i+1<k)j++;
		else if(j-i+1==k){
			ma = max(ma,c);
			if(m.find(s[i])!=m.end())c--;
			i++;
			j++;
		}
	}

	return ma;
}
