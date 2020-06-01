/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 *
 * https://leetcode-cn.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (42.02%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 34.4K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 S 包含从1到 n
 * 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,2,4]
 * 输出: [2,3]
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度范围是 [2, 10000]。
 * 给定的数组是无序的。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // vector<int> res(2, 0), cnt(nums.size(), 0);
        // for (int num : nums) ++cnt[num - 1];
        // for (int i = 0; i < nums.size(); ++i) {
        //     if (res[0] != 0 && res[1] != 0) return res;
        //     if (cnt[i] == 2) res[0] = i + 1;
        //     else if (cnt[i] == 0) res[1] = i + 1;
        // }
        // return res;

        vector<int> res(2, -1);
        for (int i : nums) {
            if (nums[abs(i) - 1] < 0) res[0] = abs(i);
            else nums[abs(i) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) res[1] = i + 1;
        }
        return res;
    }
};
// @lc code=end

