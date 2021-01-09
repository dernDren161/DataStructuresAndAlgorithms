// Problem Link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#

class Solution{
public:
	int search(string pat, string txt) {

	    if(pat.size()==0 && txt.size()==0) return 1;

	    int i=0;
	    int j=0;

	    map<char,int> master;

	    for(int i=0;i<pat.size();i++) master[pat[i]]++;

	    int c = master.size();

	    int res = 0;

	    while(j<txt.size()){

	        // this section is always for 'j'
	        auto p = master.find(txt[j]);

	        if(p != master.end()){ // if found
	            master[txt[j]]--;

	            if(master[txt[j]] == 0) c--;
	        }

	        if(j-i+1 < pat.size()) j++;

	        else if(j-i+1 == pat.size()){

	            if(c == 0) res++;

	            // rewinding
	            // this section is always for 'i', it's the 'Window sliding' section

	            auto x = master.find(txt[i]);

	            if(x != master.end()){
	                master[txt[i]]++;

	                if(master[txt[i]] == 1) c++;
	            }

	            i++;
	            j++;


	        }
	    }

	    return res;
	}

};
