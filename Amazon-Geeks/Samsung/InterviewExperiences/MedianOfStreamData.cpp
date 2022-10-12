// Problem Link: https://workat.tech/problem-solving/practice/median-from-data-stream

class MedianCalculator {
public:
    /** initialize your data structure here. */
	priority_queue<int> maxi;
	priority_queue<int,vector<int>,greater<int>>mini;
	int c;

    MedianCalculator() {
    	c = 0;
	}

    void addNum(int num) {
		c++;
    maxi.push(num);
		mini.push(maxi.top());
		maxi.pop();

		if(maxi.size()<mini.size()){
			maxi.push(mini.top());
			mini.pop();
		}
	}

    float getMedian() {
		if(c%2==0){
			return (float)((maxi.top()+mini.top())/2.0);
		}else{
			return (float)(maxi.top());
		}
    }
};
