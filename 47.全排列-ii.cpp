/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (55.04%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    51.4K
 * Total Submissions: 88.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        helper(nums, 0, visited, out, res);
        return res;
    }
    void helper(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level >= nums.size()) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            helper(nums,level + 1,visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
// @lc code=end

