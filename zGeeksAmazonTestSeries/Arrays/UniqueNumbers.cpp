// Problem Link: https://practice.geeksforgeeks.org/problems/unique-numbers3019/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1

class Solution
{

public:
    bool call(int x){

        // key, value
        // number, -1
        map<int,int> m;
        int temp;
        while(x){

            temp = x % 10;
            if(m.find(temp) != m.end()) return true;

            else if(m.find(temp) == m.end()) {
                m[temp] = -1;
            }

            x /= 10;

        }

        return false;
    }
public:
    vector<int> uniqueNumbers(int L,int R)
    {
        vector<int> vs;

        for(int i = L; i<= R; i++){
            if(call(i)) continue;

            else {
                vs.push_back(i);
            }
        }

        return vs;
    }
};
