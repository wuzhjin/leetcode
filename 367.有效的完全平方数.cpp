/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.23%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    26.5K
 * Total Submissions: 61.2K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        // long left = 0, right  = num;
        // while (left <= right) {
        //     long mid = left + (right - left) / 2;
        //     if (mid * mid == num) return true;
        //     if (mid * mid < num) left = mid + 1;
        //     else right = mid - 1;
        // }
        // return false;

        /* 一系列奇数之和 */
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
// @lc code=end

