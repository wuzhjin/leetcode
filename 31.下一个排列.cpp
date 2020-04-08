/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.17%)
 * Likes:    438
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 160.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());

        // int i, j, n = nums.size();
        // for (i = n - 2; i >= 0; --i) {
        //     if (nums[i + 1] > nums[i]) {
        //         for (j = n - 1; j > i; --j) {
        //             if (nums[j] > nums[i]) break;
        //         }
        //         swap(nums[i], nums[j]);
        //         reverse(nums.begin() + i + 1, nums.end());
        //         return;
        //     }
        // }
        // reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

