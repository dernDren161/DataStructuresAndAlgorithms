// Problem Link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1

queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll> st;

    int m = q.size();

    for(int i =0;i<k;i++){
        st.push(q.front());
        q.pop();
    }

    queue<ll> qt;

    while(!st.empty()){
        qt.push(st.top());
        st.pop();
    }

    for(int x = k;x<m;x++){
        qt.push(q.front());
        q.pop();
    }

    return qt;
}
