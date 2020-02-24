/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.13%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    63.4K
 * Total Submissions: 121.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
       string res="";
       int aLen=a.size()-1,bLen=b.size()-1,carry=0;
       while(aLen>=0||bLen>=0) {
            int aVal=aLen>=0?a[aLen--]-'0':0;
            int bVal=bLen>=0?b[bLen--]-'0':0;
            int sum=aVal+bVal+carry;
            res=to_string(sum%2)+res;
            carry=sum/2;
       }
       return carry==1?"1"+res:res;
    }
};
// @lc code=end

