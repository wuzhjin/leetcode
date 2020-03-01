/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.34%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    81.3K
 * Total Submissions: 191.3K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int left=0,right=s.size()-1;
        while(left<right) {
            if(!isStr(s[left])) ++left;
            else if(!isStr(s[right])) --right;
            else if((s[left]+32-'a')%32!=(s[right]+32-'a')%32) return false;
            else
            {
                ++left;--right;
            }
            
        }
        return true;
    }
    bool isStr(char& c) {
        if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z')) return true;
        return false;
    }
};
// @lc code=end

