/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (56.63%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    80.9K
 * Total Submissions: 137.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int m[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i] - 'a'];
        }
        for (int i = 0; i < t.size(); ++i) {
            if (--m[t[i] - 'a'] < 0) return false;
        }
        return true;
        // int vS[256] = {0}, vT[256] = {0};
        // for (int i = 0; i < s.size(); ++i) {
        //     ++vS[s[i]];
        // }
        // for (int j = 0; j < t.size(); ++j) {
        //     ++vT[t[j]];
        // }
        // for (int k = 0; k < 256; ++k) {
        //     if (vS[k] != vT[k]) return false;
        // }
        // return true;
    }
};
// @lc code=end

