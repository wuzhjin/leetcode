/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (33.35%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    67K
 * Total Submissions: 194.6K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        // double res = 1.0;
        // for (int i = n; i != 0; i /= 2) {
        //     if (i % 2 != 0) res *= x;
        //     x *= x;
        // }
        // return n < 0 ? 1 / res : res;
        double result = 1.0;
        for (unsigned i = 0, absn = abs(n); i <= 31; ++i, absn >>= 1, x *= x)
        {
            if (absn & 1)
            {
                result *= x;
            }
        }
        return n < 0 ? 1 / result : result;
    }
};
// @lc code=end

