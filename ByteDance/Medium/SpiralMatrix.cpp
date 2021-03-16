// Problem Link: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m-1;

        int left = 0;
        int right = n-1;

        int move = 0;// 0 for left to right
                    // 1 for top to bottom
                    // 2 for rigth to left
                    // 3 for bottom to top

        while(res.size()!=m*n)
        {
            if(move == 0)
            {
                for(int i=left;i<=right;i++)
                {
                    int a = matrix[top][i];
                    res.push_back(a);

                }
                 move = 1;
                    top++;
            }
             else if(move == 1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    int a = matrix[i][right];
                    res.push_back(a);

                }
                  move = 2;
                    right--;
            }
            else if(move == 2)
            {
                for(int i=right;i>=left;i--)
                {
                    int a = matrix[bottom][i];
                    res.push_back(a);

                }
                move = 3;
                    bottom--;
            }
            else if(move == 3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    int a = matrix[i][left];
                    res.push_back(a);

                }
                 move = 0;
                    left++;
            }
        }
        return res;
    }
};
