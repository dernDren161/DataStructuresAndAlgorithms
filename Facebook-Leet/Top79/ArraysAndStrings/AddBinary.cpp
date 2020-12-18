// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/263/

class Solution {
public:
    string addBinary(string a, string b) {

        /*
        Input: a = "11", b = "1"
        Output: "100"
        */

       string result = "";

        int s = 0;

        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || s == 1)
        {
            s += ((i >= 0)? a[i] - '0': 0);
            s += ((j >= 0)? b[j] - '0': 0);

            result = to_string(s % 2) + result;

            s /= 2;

            i--; j--;
        }

    return result;
    }
};
