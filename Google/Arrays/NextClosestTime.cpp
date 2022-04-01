// Problem Link: https://leetcode.com/explore/interview/card/google/59/array-and-strings/471/

class Solution {
public:
    bool isValid(string time){
        return !(time[3]>'5' || time[0]>'2'|| (time[0]=='2'&& time[1]>'3'));
    }
    string nextClosestTime(string time) {

        int n = time.size();

        set<char>digits{time[0],time[1],time[3],time[4]};
        char small = *digits.begin();
        char large = *digits.rbegin();

        for(int i=n-1;i>=0;i--){
            if(i==2) continue;
            if(time[i] < large){
                auto it = digits.upper_bound(time[i]);
                time[i] = *(it);
                if(isValid(time)) return time;
            }
            time[i] = small;
        }

        return time;
    }
};
