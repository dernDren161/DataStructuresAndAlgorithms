// Problem Link: https://leetcode.com/contest/weekly-contest-290/problems/count-lattice-points-inside-a-circle/

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {

        int n = circles.size();

        int count = 0;

        set<pair<int,int>>mySet;

        for(vector<int>x:circles){

            int r = x[0]; int c = x[1]; int radius = x[2];

            for(int i=r-radius;i<=r+radius;i++){
                for(int j=c-radius;j<=c+radius;j++){
                    if(((i-r)*(i-r))+((j-c)*(j-c)) <= radius*radius){
                        mySet.insert({i,j});
                    }
                }
            }
        }

        return mySet.size();
    }
};
