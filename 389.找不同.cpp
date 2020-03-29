/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (59.17%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 38.5K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char, int> m;
        // for (char c : s) ++m[c];
        // for (char c : t) {
        //     if (--m[c] < 0) return c;
        // }
        // return 0;
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }
};
// @lc code=end

