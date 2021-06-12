// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1#

class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    pair<int,int>m[nums.size()];  //NOTE: This m[] is necessary in the case of pairs.
	    for(int i=0;i<nums.size();i++){
	        m[i].first = nums[i];
	        m[i].second = i;
	    }

	    sort(m,m+nums.size());


	    vector<bool>vs(nums.size(),false);

	    int ans = 0;

	    for(int i=0;i<nums.size();i++){
	        if(vs[i] || m[i].second==i) continue;

	        int nodes = 0;

	        int j = i;
	        while(!vs[j]){
	            vs[j] = true;

	            j = m[j].second;
	            nodes++;
	        }
	        if(nodes)ans += (nodes-1);

	    }

	    return ans;
	}
};
