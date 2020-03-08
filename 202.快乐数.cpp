/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (55.55%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 83.4K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        /* 快慢指针，不快乐则为4，快乐为1 */
        // int fast = n, slow = n;
        // while (true) {
        //     slow = cal(slow);
        //     fast = cal(fast);
        //     fast = cal(fast);
        //     if (slow == fast) break;
        // }
        // return slow == 1;

        while (n != 1 && n != 4) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
    int cal(int n) {
        int res = 0;
        while(n) {
            int val = n % 10;
            res += val*val;
            n /= 10;
        }
        return res;
    }
};
// @lc code=end

