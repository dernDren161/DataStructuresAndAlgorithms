// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3013/

class Solution {
public:
    string multiply(string num1, string num2) {

        // 123 * 341

        // 123
        // 341
        //-----
     //    123
     //   492X
     //  369XX
     //---------
    //   41943

        int n = num1.length(); // outer loop
        int m = num2.length(); // inner loop

        if(n==0 || m==0) return "0";

        if(num1=="0" || num2=="0") return "0";

        int arr[m+n];
        memset(arr,0,sizeof(arr));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int temp = (num1[i]-'0') * (num2[j]-'0');
                arr[i+j+1] += temp;
                arr[i+j] += (arr[i+j+1]/10);
                arr[i+j+1] = arr[i+j+1] % 10;
            }
        }

        // arr[6] = {0,4,1,9,4,3};

        string res ="";

        // Two strings with sizes m and n can have
        // at maximum: m+n resultant size
        // at minimum: m+n-1 resultant size


        for(int i=0;i<m+n;i++){

            if(i==0 && arr[i]==0) continue;

                res += to_string(arr[i]);

        }

        return res;

    }
};
