// Problem Link: https://leetcode.com/problems/find-the-celebrity/submissions/


/* The knows API is defined for you.
      bool knows(int a, int b); */


// 0,1,2,3,4,5

class Solution {
public:
    int findCelebrity(int n) {



        int celeb = 0;

        // if there is atleast one celeb then this much code is enough to find the celebrity

        for(int i=1;i<n;i++){
            if(knows(celeb,i)){
                celeb = i;
            }
        }

        // but if there are none celebrities in the input, then we ought to double check the 'celeb'

        for(int i=0;i<n;i++){

            if(i==celeb) continue;

            if(knows(celeb,i) || !knows(i,celeb)) return -1;
        }

        return celeb;
    }
};
