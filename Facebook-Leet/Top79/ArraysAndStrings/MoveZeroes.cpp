// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/262/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        /*
        Input: [0,1,0,3,12]
        Output: [1,3,12,0,0]
        */

        int x = 0;
        int s = nums.size();

        for(int i=0;i<s;i++){
            if(nums[i] != 0){
                nums[x] = nums[i];
                x++;
            }
        }

        int calculated = s-x;

        while(calculated--){
            nums[s-1] = 0;
            s--;
        }
    }
};


// Problem Link: https://workat.tech/problem-solving/practice/remove-occurences
int removeOccurences(vector<int> &A, int k) {
	// add your logic here
	int c = 0;
	int x = 0;
	for(int i=0;i<A.size();i++){
		if(A[i]!=k){
			A[x++] = A[i];
			c++;
		}
	}

	int n = A.size();
	A.erase(A.begin()+c,A.end());

	return c;

}
