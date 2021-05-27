/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 *
 * https://leetcode-cn.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (41.64%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 30.1K
 * Testcase Example:  '[1,2,1]'
 *
 * 在一排树中，第 i 棵树产生 tree[i] 型的水果。
 * 你可以从你选择的任何树开始，然后重复执行以下步骤：
 *
 *
 * 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
 * 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
 *
 *
 * 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤
 * 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
 *
 * 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
 *
 * 用这个程序你能收集的水果树的最大总量是多少？
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,2,1]
 * 输出：3
 * 解释：我们可以收集 [1,2,1]。
 *
 *
 * 示例 2：
 *
 * 输入：[0,1,2,2]
 * 输出：3
 * 解释：我们可以收集 [1,2,2]
 * 如果我们从第一棵树开始，我们将只能收集到 [0, 1]。
 *
 *
 * 示例 3：
 *
 * 输入：[1,2,3,2,2]
 * 输出：4
 * 解释：我们可以收集 [2,3,2,2]
 * 如果我们从第一棵树开始，我们将只能收集到 [1, 2]。
 *
 *
 * 示例 4：
 *
 * 输入：[3,3,3,1,2,1,1,2,3,3,4]
 * 输出：5
 * 解释：我们可以收集 [1,2,1,1,2]
 * 如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 棵水果树。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
 public:
  int totalFruit(vector<int>& tree) {
    // 滑动窗口内保持两个元素。
    unordered_map<int, int> basket;
    int left = 0, len = 0, ans = 0;
    for (int i = 0; i < tree.size(); ++i) {
      basket[tree[i]]++;
      len++;
      while (basket.size() > 2) {
        basket[tree[left]]--;
        if (basket[tree[left]] == 0)
          basket.erase(tree[left]);
        left++;
        len--;
      }
      ans = max(ans, len);
    }
    return ans;
  }
};
// @lc code=end
