/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.56%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    119.6K
 * Total Submissions: 277.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //int n=digits.size();
        //for(int i=n-1;i>=0;--i){
        //    if(digits[i]==9) digits[i]=0;
        //    else{
        //        digits[i]+=1;
        //        return digits;
        //    }
        //}
        //if(digits.front()==0) digits.insert(digits.begin(),1);
        int carry=1,n=digits.size();
        for(int i=n-1;i>=0;--i){
            if(carry==0) return digits;
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
        }
        if(carry==1) digits.insert(digits.begin(),1);
        return digits;
    }
};
// @lc code=end

