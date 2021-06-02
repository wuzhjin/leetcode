/*
 * @lc app=leetcode.cn id=1525 lang=cpp
 *
 * [1525] 字符串的好分割数目
 *
 * https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string/description/
 *
 * algorithms
 * Medium (68.12%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 7K
 * Testcase Example:  '"aacaba"'
 *
 * 给你一个字符串 s ，一个分割被称为 「好分割」 当它满足：将 s 分割成 2
 * 个字符串 p 和 q ，它们连接起来等于 s 且 p 和 q 中不同字符的数目相同。
 *
 * 请你返回 s 中好分割的数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "aacaba"
 * 输出：2
 * 解释：总共有 5 种分割字符串 "aacaba" 的方法，其中 2 种是好分割。
 * ("a", "acaba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
 * ("aa", "caba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
 * ("aac", "aba") 左边字符串和右边字符串分别包含 2 个和 2
 * 个不同的字符。这是一个好分割。
 * ("aaca", "ba") 左边字符串和右边字符串分别包含 2 个和 2
 * 个不同的字符。这是一个好分割。
 * ("aacab", "a") 左边字符串和右边字符串分别包含 3 个和 1 个不同的字符。
 *
 *
 * 示例 2：
 *
 * 输入：s = "abcd"
 * 输出：1
 * 解释：好分割为将字符串分割成 ("ab", "cd") 。
 *
 *
 * 示例 3：
 *
 * 输入：s = "aaaaa"
 * 输出：4
 * 解释：所有分割都是好分割。
 *
 * 示例 4：
 *
 * 输入：s = "acbadbaada"
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * s 只包含小写英文字母。
 * 1 <= s.length <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numSplits(string s) {
    // case 1: count the number of letters at both ends and compare them.
    // int n = s.length();
    // vector<int> left(n + 2), right(n + 2);
    // bitset<26> bit_left, bit_right;

    // for (int i = 1; i <= n; ++i) {
    //   int c = s[i - 1] - 'a';
    //   if (bit_left.test(c)) {
    //     left[i] = left[i - 1];
    //   } else {
    //     bit_left.set(c);
    //     left[i] = left[i - 1] + 1;
    //   }
    // }

    // for (int i = n; i > 0; --i) {
    //   int c = s[i - 1] - 'a';
    //   if (bit_right.test(c)) {
    //     right[i] = right[i + 1];
    //   } else {
    //     bit_right.set(c);
    //     right[i] = right[i + 1] + 1;
    //   }
    // }

    // int ans = 0;
    // for (int i = 1; i < n; ++i) {
    //   if (left[i] == right[i + 1])
    //     ++ans;
    // }
    // return ans;

    // case 2: reduce repetitive loops.
    vector<int> l_dic(26, 0), r_dic(26, 0);
    int left = 0, right = 0, ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      right += (r_dic[c] == 0);
      ++r_dic[c];
    }

    for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a';
      left += (l_dic[c] == 0);
      ++l_dic[c];
      --r_dic[c];
      right -= (r_dic[c] == 0);
      ans += (left == right);
    }
    return ans;
  }
};
// @lc code=end
