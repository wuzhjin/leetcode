/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 *
 * https://leetcode-cn.com/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (71.28%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 11.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * 给你一个 m x n 的矩阵 mat 和一个整数 k
 * ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素
 * mat[r][c] 的和： 
 *
 *
 * i - k
 * j - k  且
 * (r, c) 在矩阵内。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 * 输出：[[12,21,16],[27,45,33],[24,39,28]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
 * 输出：[[45,45,45],[45,45,45],[45,45,45]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int get(const vector<vector<int>>& pre, int m, int n, int x, int y) {
    x = max(min(x, m), 0);
    y = max(min(y, n), 0);
    return pre[x][y];
  }

  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        P[i][j] =
            P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = get(P, m, n, i + k + 1, j + k + 1) -
                    get(P, m, n, i - k, j + k + 1) -
                    get(P, m, n, i + k + 1, j - k) + get(P, m, n, i - k, j - k);
      }
    }
    return ans;
  }
};
// @lc code=end
