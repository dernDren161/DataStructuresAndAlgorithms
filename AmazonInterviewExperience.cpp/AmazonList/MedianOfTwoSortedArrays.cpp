// Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Video Link: https://www.youtube.com/watch?v=LPFhl65R7ww&ab_channel=TusharRoy-CodingMadeSimple

// T.C: O(log(min(n,m)))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        if(m<n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int s = 0;
        int e = n;  // NOTE: Not (n-1) but instead n, notice,,,
        int total = n+m;

        while(s<=e)
        {
            int mid1 = (s+e)/2;
            int mid2 = (total+1)/2 - mid1;

            int l1 = (mid1 == 0 ? INT_MIN : nums1[mid1-1]);
            int l2 = (mid2 == 0 ? INT_MIN : nums2[mid2-1]);

            int r1 = (mid1 == n ? INT_MAX : nums1[mid1]);
            int r2 = (mid2 == m ? INT_MAX : nums2[mid2]);

            if(l1<=r2 && l2<=r1)
            {
                if(total % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if(l1 > r2)
            {
                e = mid1-1;
            }
            else
            {
                s = mid1+1;
            }

        }

        return 0.0;

    }
};
