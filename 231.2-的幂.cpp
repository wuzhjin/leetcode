/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (46.81%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    49K
 * Total Submissions: 102.5K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if (n < 1) return false;
        // while (n != 1) {
        //     if (n % 2 != 0) return false;
        //     n /= 2;
        // }
        // return true;

        // if (n < 1) return false;
        // while (n != 1) {
        //     if (n & 1) return false;
        //     n = n >> 1;
        // }
        // return true;

        return (n > 0) && (!(n & (n - 1)));
    }
};
// @lc code=end

