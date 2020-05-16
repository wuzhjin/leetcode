/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (34.61%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 74.6K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*超时*/
        // int res = 0, start = -1, n = nums.size();
        // for (int i = 1; i < n; ++i) {
        //     if (nums[i] < nums[i - 1]) {
        //         int j = i;
        //         while (j > 0 && nums[j] < nums[j - 1]) {
        //             swap(nums[j], nums[j - 1]);
        //             --j;
        //         }
        //         if (start == -1 || start > j) start = j;
        //         res = i - start + 1;
        //     }
        // }
        // return res;
        

        // int n = nums.size(), i = 0, j = n - 1;
        // vector<int> t = nums;
        // sort(t.begin(), t.end());
        // while (i < n && nums[i] == t[i]) ++i;
        // while (j > i && nums[j] == t[j]) --j;
        // return j - i + 1;


        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) end = i;
            if (mn < nums[n - 1 - i]) start = n - 1 - i;
        }
        return end - start + 1;
    }
};
// @lc code=end

