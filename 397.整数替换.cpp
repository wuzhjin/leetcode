/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 *
 * https://leetcode-cn.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (35.89%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 34.2K
 * Testcase Example:  '8'
 *
 * 给定一个正整数 n ，你可以做如下操作：
 *
 *
 * 如果 n 是偶数，则用 n / 2替换 n 。
 * 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
 *
 *
 * n 变为 1 所需的最小替换次数是多少？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 8
 * 输出：3
 * 解释：8 -> 4 -> 2 -> 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 7
 * 输出：4
 * 解释：7 -> 8 -> 4 -> 2 -> 1
 * 或 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 4
 * 输出：2
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
  int integerReplacement(int n) {
    // case 1: direct use recursion.
    // if (n == 1)
    //   return 0;
    // if (n % 2 == 0) {
    //   return 1 + integerReplacement(n / 2);
    // } else {
    //   long long t = n;
    //   return 2 + min(integerReplacement((t + 1) / 2),
    //                  integerReplacement((t - 1) / 2));
    // }

    // case 2: use iteration.
    long long t = n;
    int cnt = 0;
    while (t > 1) {
      ++cnt;
      if (t & 1) {
        if ((t & 2) && (t != 3))
          ++t;
        else
          --t;
      } else {
        t >>= 1;
      }
    }
    return cnt;
  }
};
// @lc code=end
