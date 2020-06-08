/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (45.07%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 58.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 3
 * 解释: 最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 1
 * 解释: 最长连续递增序列是 [2], 长度为1。
 * 
 * 
 * 
 * 
 * 注意：数组长度不会超过10000。
 * 
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // int res = 0, cnt = 0, cur = INT_MAX;
        // for (int num : nums) {
        //     if (num > cur) ++cnt;
        //     else cnt = 1;
        //     res = max(res, cnt);
        //     cur = num;
        // }
        // return res;
        int res = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i - 1] < nums[i]) res = max(res, ++cnt);
            else cnt = 1;
        }
        return res;
    }
};
// @lc code=end

