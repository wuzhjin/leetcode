/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.68%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    45.7K
 * Total Submissions: 139.9K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        /* 埃拉托斯特尼筛法??? */
        vector<bool> prime(n, true);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) continue;
            ++res;
            for (int j = 2; j * i < n; ++j) {
                prime[i * j] = false;
            }
        }
        return res;
    }
};
// @lc code=end

