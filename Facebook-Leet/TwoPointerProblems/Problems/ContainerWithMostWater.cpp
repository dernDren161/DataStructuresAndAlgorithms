// Problem Link: https://leetcode.com/problems/container-with-most-water/submissions/

// Slightly different in the Problem statement as compared to the one in the 'Stack' directory

class Solution {
public:
    int maxArea(vector<int>& height) {

        if(height.size() == 0) return 0;

        int n = height.size();
        int l = 0;
        int r = n-1;

        int m = 0;
        int area;

        while(l<r){

            area = (min(height[l],height[r])) * (r-l);

            m = max(m,area);

            if(height[l] < height[r]){ // means if l was the smallest then this 'area' was the maximum                                           for l, so perform l++, since the maximum area for l has                                                 already just been taken.
                l++;
            }else{
                r--;
            }
        }

        return m;
    }
};
