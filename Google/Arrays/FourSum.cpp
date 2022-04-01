//Problem Link: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> res;

        if(n<4) return {};

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int a = nums[i];
                for(int j=i+1;j<n-2;j++){
                    int b = nums[j];
                    if(j==i+1 || nums[j]!=nums[j-1]){
                        int x = j+1;
                        int y = n-1;
                        int sum = target - (a+b);

                        while(x<y){
                            if(nums[x]+nums[y] == sum){
                                vector<int> ui;
                                ui.push_back(a); ui.push_back(b); ui.push_back(nums[x]);
                                ui.push_back(nums[y]);
                                res.push_back(ui);
                                ui.clear();

                                while(x<y && nums[x]==nums[x+1])x++;
                                while(x<y && nums[y]==nums[y-1])y--;
                                x++;
                                y--;
                            }else if(nums[x]+nums[y] < sum){
                                x++;
                            }else y--;
                        }
                    }
                }
            }
        }

        if(res.size()==0) return {};

        return res;
    }
};
