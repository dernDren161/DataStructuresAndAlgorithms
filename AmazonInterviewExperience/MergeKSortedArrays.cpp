// Problem Link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#
// T.C: O(k*k log k);
// S.C: O(k*k)

class Solution
{
    public:
    //Function to merge k sorted arrays.

    struct comp{
        bool operator()(pair<int,int>a, pair<int,int>b){
            return a.first > b.first;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        int row = arr.size();
        int col = arr[0].size();

        vector<int> ans(k*k);

        // key - the number and value - the row of the number
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;

        for(int i=0;i<row;i++){
            pq.push(make_pair(arr[i][0],i));
        }

        int p = 0;
        int columnIndex[k];

        for(int i=0;i<k;i++)columnIndex[i]=0;

        for(int i=0;i<k*k;i++){
            int x = pq.top().first;
            ans[p++] = x;
            int rowIndex = pq.top().second;
            pq.pop();

            if(columnIndex[rowIndex]<k-1){ // NOTE: Note this 'k-1' part.
                ++columnIndex[rowIndex];
                pq.push(make_pair(arr[rowIndex][columnIndex[rowIndex]],rowIndex));
            }
        }

        return ans;
    }
};
