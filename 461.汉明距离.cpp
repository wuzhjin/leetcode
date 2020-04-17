/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 *
 * https://leetcode-cn.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (73.25%)
 * Likes:    261
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 65.4K
 * Testcase Example:  '1\n4'
 *
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 * 
 * 注意：
 * 0 ≤ x, y < 2^31.
 * 
 * 示例:
 * 
 * 
 * 输入: x = 1, y = 4
 * 
 * 输出: 2
 * 
 * 解释:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * 上面的箭头指出了对应二进制位不同的位置。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        // int res = 0;
        // for (int i = 0; i < 32; ++i) {
        //     if ((x & (1 << i)) ^ (y & (1 << i))) ++res;
        // }
        // return res;
        
        int res = 0, exc = x ^ y;
        while (exc) {
            ++res;
            exc &= (exc - 1);
        }
        return res;
    }
};
// @lc code=end

