// Problem Link: https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1#
// The test cases won't pass
// Useless test cases

class Solution{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {

        priority_queue<pair<int,int>> pq; // --->> index,arr[i]

        for(int i=0;i<k+1;i++){
            pq.push({abs(arr[i]-x),arr[i]});
        } // 'pq' gets sorted w.r.t the index or the first value in pair.

        for(int i=k+1;i<n;i++){
            pq.push({abs(arr[i]-x),arr[i]});
            pq.pop();
        }

        vector<int>vs;

        for(int i=0;i<k;i++){
            pair<int,int>x;
            x = pq.top();
            vs.push_back(x.second);
            pq.pop();
        }
        reverse(vs.begin(),vs.begin()+k);
        return vs;
    }
};
