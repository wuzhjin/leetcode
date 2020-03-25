/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (52.29%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 45.9K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        /* 在二进制下来看，不考虑进位的加，0+0=0，0+1=1, 1+0=1，1+1=0，这就是异或的运算规则，
        如果只考虑进位的加 0+0=0, 0+1=0, 1+0=0, 1+1=1，而这其实这就是'与'的运算，
        而第三步在将两者相加时，再递归调用这个算法，
        终止条件是当进位为0时，直接返回第一步的结果。*/
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b & 0x7fffffff) << 1;
        return getSum(sum, carry);
    }
};
// @lc code=end

