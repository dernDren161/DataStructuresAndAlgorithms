// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/293/
// T.C: O(n*n!)
// S.C(with the map): O(n*n!)

class Solution {
public:

    vector<vector<int>> res;

    //NOTE: Here neither x or sz is being passed by reference, but instead is being called through by value, important

    void call(vector<int> nums, int x, int sz){

        if(x == sz){
          res.push_back(nums);
            return;
        }

        // very very important
        // it is because of this declaration of 'map' at this position do we get the first form as is,
        // fo ex: if the input is: "ABC" then,
        // because of the following line the first element in the 2D vector is "ABC" only.

        // and also this avoids the duplication of the same combination as well.

        // NOTE: This map declaration is unique to each recursive call, meaning, one 'm' instance remains intact till the (n-1) occurence inside the loop.
        map<int,int> m;
        for(int i=x;i<sz;i++){

            ++m[nums[i]];// NOTE: Here we use 'i' instead of 'x' goes on to prove that the created map is just for the instances inside the loop and not in the individual recursion calls.

            if(m[nums[i]] == 1){
                swap(nums[x],nums[i]);  // NOTE: @ SCS
                call(nums,x+1,sz);
                swap(nums[x],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        /*
        Input: nums = [1,1,2]
        Output:
        [[1,1,2],
        [1,2,1],
        [2,1,1]]
        */

        if(nums.size() == 0) return {};

        int x = 0;
        int s = nums.size();

        call(nums,x,s);

        return res;
    }
};

//NOTE: SImilarly if the duplication is allowed, then

void permute(string a, int x, int sz)
{
    // Base case
    if (x == sz)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = x; i < sz; i++)
        {

            // Swapping done
            swap(a[x], a[i]);

            // Recursion called
            permute(a, x+1, sz);

            //backtrack
            swap(a[x], a[i]);
        }
    }
}
