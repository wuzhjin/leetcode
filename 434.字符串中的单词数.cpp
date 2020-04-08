/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (32.56%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 42.1K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        // int res = 0;
        // istringstream is(s);
        // string t = "";
        // while (getline(is, t, ' ')) {
        //     if (t.empty()) continue;
        //     ++res;
        // }
        // return res;

        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            ++res;
            while (i < n && s[i] != ' ') ++i;
        }
        return res;
    }
};
// @lc code=end

