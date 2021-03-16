// Problem Link: https://leetcode.com/problems/last-stone-weight-ii/

// a variation of the 'minimum subset sum difference'

// Normal SSP: * * * *
//             |
//             |
//             |

// This SSP: | * * *
//           |
//           |
//           |

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        // subset sum problem variation

        int sum = 0;
        for(int i=0;i<stones.size();i++){
            sum += stones[i];
        }
        int n = stones.size();

        bool mat[n+1][sum+1];

        for(int i=1;i<=sum;i++) mat[0][i]=false;
        for(int i=0;i<=n;i++) mat[i][0] = true;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){

                if(j>=stones[i-1]){
                    mat[i][j] = mat[i-1][j] || mat[i-1][j-stones[i-1]];
                }else{
                    mat[i][j] = mat[i-1][j];
                }
            }
        }
        // constructed the boolean from SSP;

        int ans = INT_MIN;

        for(int i=sum/2;i>=0;i--){
            if(mat[n][i]){
                ans = sum - 2*i;
                break;
            }
        }

        return ans;
    }
};
