/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (50.49%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 80.8K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int res = 0;
        bool mid = false;
        for (char c : s) ++m[c];
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            res += iter->second;
            if (iter->second % 2 == 1) {
                res -= 1;
                mid = true;
            }
        }
        return mid ? res + 1 : res;
    }
};
// @lc code=end

