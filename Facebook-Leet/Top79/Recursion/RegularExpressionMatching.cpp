// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/307/

// For full version of code, i.e memoization or top down DP refer to this blog:

// Blog Link: https://coderscat.com/leetcode-regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {

    if(s.size() == NULL && p.size() == NULL) return true;

    if(p.size() == NULL) return false;

    bool first_match = !s.empty() && (s[0] == p[0] || '.' == p[0]);

    if (p.size() >= 1 && '*' == p[1])
      return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    else
      return  first_match && isMatch(s.substr(1), p.substr(1));

    }
};
