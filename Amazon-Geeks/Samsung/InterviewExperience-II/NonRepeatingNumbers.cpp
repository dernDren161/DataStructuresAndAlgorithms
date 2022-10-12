// Problem Link: https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int a=0;
        int b=0;

        int Xor = nums[0];

        for(int i=1;i<nums.size();i++){
            Xor ^= nums[i];
        }

        // Getting the rightmost set bit
        int n = Xor & ~(Xor-1);

        for(int i=0;i<nums.size();i++){
            if(nums[i] & n){
                a ^= nums[i];
            }else{
                b ^= nums[i];
            }
        }

        vector<int>vs;
        vs.push_back(min(a,b));
        vs.push_back(max(a,b));

        return vs;
    }
};
