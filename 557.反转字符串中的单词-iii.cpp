/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (68.21%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    53.5K
 * Total Submissions: 75.9K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // if(s.empty()) return s;
        // string res = "", t = "";
        // istringstream is(s);
        // while (is >> t) {
        //     reverse(t.begin(), t.end());
        //     res += t + " ";
        // }
        // res.pop_back();
        // return res;
        int start = 0, end = 0, n = s.size();
        while (start < n && end < n) {
            while (end < n && s[end] != ' ') ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            start = ++end;
        }
        return s;
    }
};
// @lc code=end

