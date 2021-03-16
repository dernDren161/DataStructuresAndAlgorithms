// Problem Link: https://leetcode.com/problems/top-k-frequent-elements/

unordered_map<int,int>hash;
        int curr_max=0,curr_elem;
        vector<int>result;
        //Store the the count of each unique element
        for(auto x : nums)
        hash[x]+=1;
        //Keep finding the Largest frequency element and remove it from the hashmap
        while(k>0)
        {
         for(auto x : hash)
         {
             if(x.second>curr_max)
             {
                  curr_elem=x.first;
                 curr_max=x.second;
             }
         }
        result.push_back(curr_elem);
        hash.erase(curr_elem);
        curr_max=0;
        k--;
        }
        return result;
