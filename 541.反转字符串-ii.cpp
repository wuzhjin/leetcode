/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode-cn.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (49.64%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 27.3K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k
 * 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
 * 
 * 示例:
 * 
 * 
 * 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * 
 * 
 * 要求:
 * 
 * 
 * 该字符串只包含小写的英文字母。
 * 给定字符串的长度和 k 在[1, 10000]范围内。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};
// @lc code=end

