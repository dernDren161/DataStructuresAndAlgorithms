// Discuss Link: https://leetcode.com/discuss/interview-question/1531250/Google-or-Phone-Screen-or-Pairs-of-Non-overlapping-Subarrays

/* O(1) */
private int totalSubarrays(int n) {
    return n*(n+1)/2;
}

/* O(n) */
private int nonOverlappingSubarrays(int n) {
    int count = 0;
    for(int i=1;i<n;++i) {
        // count += totalSubarrays(i) * totalSubarrays(n-i);    /* repetitive */
        count += (i+1) * totalSubarrays(n-i);
    }
    return count;
}
