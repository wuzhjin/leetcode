/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (46.76%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 23.1K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool pos = num > 0;
        string res = "";
        while (num != 0) {
            res = to_string(abs(num % 7)) + res;
            num /= 7;
        }
        return pos ? res : "-" + res;
    }
};
// @lc code=end

