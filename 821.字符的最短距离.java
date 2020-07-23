import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=821 lang=java
 *
 * [821] 字符的最短距离
 *
 * https://leetcode-cn.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (66.99%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 20.1K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
 * 
 * 示例 1:
 * 
 * 
 * 输入: S = "loveleetcode", C = 'e'
 * 输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 说明:
 * 
 * 
 * 字符串 S 的长度范围为 [1, 10000]。
 * C 是一个单字符，且保证是字符串 S 里的字符。
 * S 和 C 中的所有字母均为小写字母。
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] shortestToChar(String S, char C) {
        int n = S.length();
        int[] res = new int[n];
        for (int i = 0; i < n; ++i) res[i] = n;
        for (int i = 0; i < n; ++i) {
            if (S.toCharArray()[i] != C) continue;
            res[i] = 0;
            for (int j = i + 1; j < n && S.toCharArray()[j] != C; ++j) {
                res[j] = Math.min(res[j], j - i);
            }
            for (int j = i - 1; j >= 0 && S.toCharArray()[j] != C; --j) {
                res[j] = Math.min(res[j], i - j);
            }
        }
        return res;
        // int N = S.length();
        // int[] ans = new int[N];
        // int prev = Integer.MIN_VALUE / 2;

        // for (int i = 0; i < N; ++i) {
        //     if (S.charAt(i) == C) prev = i;
        //     ans[i] = i - prev;
        // }

        // prev = Integer.MAX_VALUE / 2;
        // for (int i = N-1; i >= 0; --i) {
        //     if (S.charAt(i) == C) prev = i;
        //     ans[i] = Math.min(ans[i], prev - i);
        // }

        // return ans;
    }
}
// @lc code=end

