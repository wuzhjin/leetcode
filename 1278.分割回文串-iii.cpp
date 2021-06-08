/*
 * @lc app=leetcode.cn id=1278 lang=cpp
 *
 * [1278] 分割回文串 III
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-iii/description/
 *
 * algorithms
 * Hard (58.74%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 5.1K
 * Testcase Example:  '"abc"\n2'
 *
 * 给你一个由小写字母组成的字符串 s，和一个整数 k。
 * 
 * 请你按下面的要求分割字符串：
 * 
 * 
 * 首先，你可以将 s 中的部分字符修改为其他的小写英文字母。
 * 接着，你需要把 s 分割成 k 个非空且不相交的子串，并且每个子串都是回文串。
 * 
 * 
 * 请返回以这种方式分割字符串所需修改的最少字符数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abc", k = 2
 * 输出：1
 * 解释：你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aabbc", k = 3
 * 输出：0
 * 解释：你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。
 * 
 * 示例 3：
 * 
 * 输入：s = "leetcode", k = 8
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= s.length <= 100
 * s 中只含有小写英文字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int cost(string& s, int left, int right) {
    //     int res = 0;
    //     for (int i = left, j = right; i < j; ++i, --j) {
    //         if (s[i] != s[j]) ++res;
    //     }
    //     return res;
    // }

    int palindromePartition(string s, int k) {
        int n = s.size();

        // optimize cost function.
        vector<vector<int>> cost(n, vector<int>(n));
        for (int span = 2; span <= n; ++span) {
            for (int i = 0; i <= n - span; ++i) {
                int j = i + span - 1;
                cost[i][j] = cost[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                if (j == 1) {
                    dp[i][j] = cost[0][i - 1];
                    // dp[i][j] = cost(0, i - 1);
                } else {
                    for (int i0 = j - 1; i0 < i; ++i0) {
                        // dp[i][j] = min(dp[i][j], dp[i0][j - 1] + cost(s, i0, i - 1));
                        dp[i][j] = min(dp[i][j], dp[i0][j - 1] + cost[i0][i - 1]);
                    }
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

