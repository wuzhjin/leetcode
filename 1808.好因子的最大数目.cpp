/*
 * @lc app=leetcode.cn id=1808 lang=cpp
 *
 * [1808] 好因子的最大数目
 *
 * https://leetcode-cn.com/problems/maximize-number-of-nice-divisors/description/
 *
 * algorithms
 * Hard (26.11%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 8.8K
 * Testcase Example:  '5'
 *
 * 给你一个正整数 primeFactors 。你需要构造一个正整数 n ，它满足以下条件：
 * 
 * 
 * n 质因数（质因数需要考虑重复的情况）的数目 不超过 primeFactors 个。
 * n 好因子的数目最大化。如果 n 的一个因子可以被 n 的每一个质因数整除，我们称这个因子是 好因子 。比方说，如果 n = 12 ，那么它的质因数为
 * [2,2,3] ，那么 6 和 12 是好因子，但 3 和 4 不是。
 * 
 * 
 * 请你返回 n 的好因子的数目。由于答案可能会很大，请返回答案对 10^9 + 7 取余 的结果。
 * 
 * 请注意，一个质数的定义是大于 1 ，且不能被分解为两个小于该数的自然数相乘。一个数 n 的质因子是将 n 分解为若干个质因子，且它们的乘积为 n
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：primeFactors = 5
 * 输出：6
 * 解释：200 是一个可行的 n 。
 * 它有 5 个质因子：[2,2,2,5,5] ，且有 6 个好因子：[10,20,40,50,100,200] 。
 * 不存在别的 n 有至多 5 个质因子，且同时有更多的好因子。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：primeFactors = 8
 * 输出：18
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long quickPow(int p, int q, int mod) {
        long ans = 1;
        long base = p;
        while (q != 0) {
            if (q & 1) {
                ans = ans * base % mod;
            }
            base = base * base % mod;
            q >>= 1;
        }
        return ans;
    }

    int maxNiceDivisors(int primeFactors) {
        int mod = 1e9 + 7;
        if (primeFactors <= 3) {
            return primeFactors;
        }

        int quotient = primeFactors / 3;
        int remainder = primeFactors % 3;
        if (remainder == 1) {
            return quickPow(3, quotient - 1, mod) * 4 % mod;
        } else if (remainder == 2) {
            return quickPow(3, quotient, mod) *2 % mod;
        } else {
            return quickPow(3, quotient, mod);
        }
    }
};
// @lc code=end

