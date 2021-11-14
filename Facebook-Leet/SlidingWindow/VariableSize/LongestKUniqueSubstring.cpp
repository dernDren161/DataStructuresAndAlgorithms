// Problem Link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0#

#include<bits/stdc++.h>
using namespace std;

map<char,int>& call(int i, int j, string s){

    map<char,int> x;

    for(int m=i;m<=j;m++) x[s[m]]++;

    return x;
}

int call(string s, int k){

    int i=0;
    int j=0;
    int maxi = 0;
    map<char,int> m;

    while(j<s.length()){

        m.clear();

        m = call(i,j,s);


        if(m.size() < k) j++; // NOTE: Note this variation

        else if(m.size() == k){
            maxi = max(maxi,j-i+1);
            j++;
        }
        else if(m.size() > k){

            while(m.size()>k){
                m[s[i]]--;

                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;

        }
    }

    return maxi;
}

int main() {

	int t;
	string s;
	int k;

	cin >> t;
	while(t--){
	    cin >> s;
	    cin >> k;

	    cout << call(s,k) << endl;
	}

	return 0;
}
