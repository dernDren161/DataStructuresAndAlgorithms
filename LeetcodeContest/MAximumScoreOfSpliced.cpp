// Problem Link: https://leetcode.com/contest/weekly-contest-299/problems/maximum-score-of-spliced-array/

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        int nOne = nums1.size();
        int nTwo = nums2.size();

        int cOne = 0; int cTwo = 0;
        int resOne=INT_MIN; int resTwo=INT_MIN;
        int sumOne = 0; int sumTwo = 0;

        for(int i=0;i<nOne;i++){
            cOne += (nums2[i]-nums1[i]);
            cTwo += (nums1[i]-nums2[i]);
            if(cOne<0)cOne=0;
            if(cTwo<0)cTwo=0;
            resOne = max(resOne,cOne);
            resTwo = max(resTwo,cTwo);
            sumOne += nums1[i];
            sumTwo += nums2[i];
        }

        return max(sumOne+resOne,sumTwo+resTwo);
    }
};
