// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-all-prime-numbers-between-1-and-n4404/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=2&query=company[]SamsungproblemStatusunsolvedpage2company[]Samsung#

class Solution{
	public:
   	long long int prime_Sum(int n){
   	    // Code here
   	    bool prime[n+1];

   	    memset(prime,true,sizeof(prime));

   	    for(int i=2;i*i<=n;i++){// takes: 2,3,5,7,...
   	        if(prime[i]){
   	            for(int j= 2 *i;j<=n;j+=i){
   	                prime[j] = false;
   	            }
   	        }
   	    }

   	    long long s = 0;
   	    for(int i=2;i<=n;i++){
   	        if(prime[i]){
   	            s += i;  
   	        }
   	    }

   	    return s;
   	}
};
