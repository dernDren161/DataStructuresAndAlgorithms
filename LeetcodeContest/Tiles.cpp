// Problem Link: https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {

        int n = tiles.size();
        int i; int j; i= 0; j = 0;

        int ans = 0;
        int cover = 0;
        int partial;

        sort(tiles.begin(),tiles.end());

        while(j<n && ans<len){

            if(tiles[i][0]+len > tiles[j][1]){
                cover += (tiles[j][1]-tiles[j][0]+1);
                ans = max(ans,cover);
                j++;
            }else{
                partial = max(0,tiles[i][0]+len-tiles[j][0]);
                ans = max(ans,cover+partial); // note i am not adding the partial to cover
                cover -= (tiles[i][1]-tiles[i][0]+1);
                i++;
            }
        }

        return ans;
    }
};
