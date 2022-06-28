// Problem Link: https://leetcode.com/problems/two-sum/
// T.C: O(n)
// S.C: O(n)


// https://workat.tech/problem-solving/practice/k-diff-pairs
int kDiffPairs(vector<int> &arr, int k) {
	// add your logic here
	int n = arr.size();
	int l = 0;
	int r = n-1;
	int c = 0;

	map<int,int>m;
	// a + b
	// b-a ==k
	//
	for(int i=0;i<n;i++){
		if(m.find(arr[i]-k)==m.end()){
			m[arr[i]]++;
		}else{
			if(m.find(arr[i])==m.end()){
				c++;
			m[arr[i]]++;
			}

		}
	}

	return c;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>m; // number, index

        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])==m.end()){ // if not found
                m[nums[i]] = i;
            }else{
                return {m[target-nums[i]],i};
            }
        }

        return {};
    }
};
