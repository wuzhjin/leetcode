/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.66%)
 * Likes:    797
 * Dislikes: 0
 * Total Accepted:    189.1K
 * Total Submissions: 333.7K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0)) return false;
        int div=1;
        while(x/div>=10)
        {
            div*=10;
        }
        while(x)
        {
            if(x%10!=x/div) return false;
            x=x%div;
            x=x/10;
            div/=100;
        }
        return true;
        //转string
        // if(x<0) return false;
        // char c;
        // string s="";
        // while(x)
        // {
        //     c='0'+x%10;
        //     s=c+s;
        //     x=x/10;
        // }
        // for(int i=0,j=s.size()-1;i<j;i++,j--)
        // {
        //     if(s[i]!=s[j]) return false;
        // }
        // return true;
    }
};
// @lc code=end

