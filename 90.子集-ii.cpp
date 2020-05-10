/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.80%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 53.5K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        helper(nums, 0, out, res);
        return res;
    }
    void helper(vector<int> &nums, int pos,  vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
};
// @lc code=end

