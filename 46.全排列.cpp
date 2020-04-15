/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (72.41%)
 * Likes:    610
 * Dislikes: 0
 * Total Accepted:    102.6K
 * Total Submissions: 137.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        helper(nums, 0, visited, out, res);
        return res;
    }
    void helper(vector<int>& nums, int level, vector<int>& visited, vector<int>& out,
vector<vector<int>>& res) {
        if (level == nums.size()) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            helper(nums, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
// @lc code=end

