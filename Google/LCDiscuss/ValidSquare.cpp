// Problem Link: https://leetcode.com/problems/valid-square/

class Solution {
public:
    int callDist(vector<int>& a, vector<int>&b){
        return (pow(b[0]-a[0],2) + pow(b[1]-a[1],2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<int>vs;

        vs.push_back(callDist(p1,p2));
        vs.push_back(callDist(p1,p3));
        vs.push_back(callDist(p1,p4));
        vs.push_back(callDist(p2,p3));
        vs.push_back(callDist(p2,p4));
        vs.push_back(callDist(p3,p4));

        sort(vs.begin(),vs.end());

        int side = vs[0];
        int diagonal = vs[5];

        int s = 0; int d = 0;

        for(int i=0;i<6;i++){
            if(vs[i]==side){
                s++;
            }else if(vs[i]==diagonal){
                d++;
            }
        }

        return (s==4)&&(d==2);

    }
};
