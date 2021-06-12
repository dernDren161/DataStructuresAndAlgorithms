// Problem Link: https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#

int countRev (string expr)
{
    // your code here
    int len = expr.length();


	if (len % 2 != 0) {
		return -1;
	}
	int left_brace = 0, right_brace = 0;
	int ans;
	for (int i = 0; i < len; i++) {

		if (expr[i] == '{') {
			left_brace++;
		}


		else {
			if (left_brace == 0) {
				right_brace++;
			}
			else {
				left_brace--;
			}
		}
	}
	ans = (left_brace+1) / 2+ (right_brace+1) / 2;
	return ans;
}
