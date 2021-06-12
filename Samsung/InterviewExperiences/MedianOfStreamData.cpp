// Problem Link: https://leetcode.com/problems/find-median-from-data-stream/submissions/

class MedianFinder {
public:
    /** initialize your data structure here. */

    public:
        int c;
        priority_queue<int> maxi;
        priority_queue<int,vector<int>,greater<int>> mini;

    MedianFinder() {
        c = 0;
    }

    void addNum(int num) {
        c++;
        if(!maxi.empty()&&num>maxi.top())mini.push(num);
        else maxi.push(num);

        int s1=maxi.size();
        int s2=mini.size();

        if(s1-s2 > 1){
            mini.push(maxi.top());
            maxi.pop();
        }else if(s1-s2<0){
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        if(c%2!=0) return (double)(maxi.top());
        return ((double)((maxi.top()+mini.top())/2.0));
    }
};
