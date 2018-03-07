/*
 * [724] Find Pivot Index
 *
 * https://leetcode.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (39.53%)
 * Total Accepted:    14.4K
 * Total Submissions: 36.5K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * Given an array of integers nums, write a method that returns the "pivot"
 * index of this array.
 * 
 * We define the pivot index as the index where the sum of the numbers to the
 * left of the index is equal to the sum of the numbers to the right of the
 * index.
 * 
 * If no such index exists, we should return -1. If there are multiple pivot
 * indexes, you should return the left-most pivot index.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * nums = [1, 7, 3, 6, 5, 6]
 * Output: 3
 * Explanation: 
 * The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the
 * sum of numbers to the right of index 3.
 * Also, 3 is the first index where this occurs.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * nums = [1, 2, 3]
 * Output: -1
 * Explanation: 
 * There is no index that satisfies the conditions in the problem statement.
 * 
 * 
 * 
 * Note:
 * The length of nums will be in the range [0, 10000].
 * Each element nums[i] will be an integer in the range [-1000, 1000].
 * 
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        vector<int> l(n, 0), r(n, 0);
        l[0] = nums[0]; r[n-1] = nums[n-1];
        for (int i = 1; i < n; ++i) l[i] = l[i-1] + nums[i];
        for (int i = n-2; i >= 0; --i) r[i] = r[i+1] + nums[i];
        if (r[1] == 0) return 0;
        for (int i = 1; i < n-1; ++i) if (l[i-1] == r[i+1]) return i;
        if (l[n-2] == 0) return n-1;

        return -1;
    }
};
