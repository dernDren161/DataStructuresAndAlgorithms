// Problem Link: https://leetcode.com/problems/min-stack/

// NOTe: The trick here is to find the minimum most element in O(1) time complexity

class MinStack {
public:
    /** initialize your data structure here. */

    stack<pair<int,int>> st; // number,minimum element till the 'number'

    MinStack() {

    }

    void push(int val) {

        int minimum;

        if(st.empty()){
            minimum = val;
        }else{
            minimum = min(val,st.top().second);
        }

        st.push({val,minimum});
    }

    void pop() {
        if(!st.empty()) st.pop();
    }

    int top() {
        if(!st.empty()) return st.top().first;
        return -1;
    }

    int getMin() {
        if(!st.empty()) return st.top().second;
        return -1;
    }
};
