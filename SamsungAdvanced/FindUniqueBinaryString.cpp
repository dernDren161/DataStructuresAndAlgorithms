// Problem Link: https://leetcode.com/problems/find-unique-binary-string/

class Solution {
public:
    void call(vector<string>&nums, int r, int c, map<string,int>&myMap, string temp, int x,string& store){

        if(temp.size()==c){
            if(myMap.find(temp)==myMap.end()){
                store = temp;
                return;
            }
            return;
        }
        if(x==c){
            return;
        }
        call(nums,r,c,myMap,temp+"0",x+1,store);
        call(nums,r,c,myMap,temp+"1",x+1,store);
    }

    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();
        map<string,int>myMap;
        for(string x:nums)myMap[x]++;
        int r = nums.size();
        int c = nums[0].size();

        string temp = "";
        string store="";
        call(nums,r,c,myMap,temp,0,store);
        return store;
    }
};
