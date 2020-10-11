// Problem Link: https://practice.geeksforgeeks.org/problems/print-first-letter-of-every-word-in-the-string3632/1/?company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1

// Three things to learn from this programm:

// 1. String is also an array, so could be accessed as S[i];
// 2. Strings's length is calculated using '.length()' instead of '.size()'
// 3. Copying characters into a string is done by: string a = string(1,s[i]), where 1 signifies the number of characteres to be copied.
 

class Solution{
public:

	string firstAlphabet(string S)
	{
	    int temp = S.length();

	    string ss = string(1,S[0]);

	    bool b = true;
	    for(int i=1;i<temp;i++){
	        if(!b){
	            ss = ss + S[i];
	            b = true;
	        }
	        if(S[i] == ' ') b = false;
	    }
	 return ss;

	}
};
