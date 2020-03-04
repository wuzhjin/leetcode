/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.44%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    115.3K
 * Total Submissions: 186.8K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
//        int cnt = 0, res = 0;
//        for ( int i = 0; i < nums.size(); ++i) {
//            if (cnt == 0) {
//                res = nums[i];
//                ++cnt;
//            }
//            else {
//                res == nums[i] ? ++cnt : --cnt;
//            }
//        }
//        return res;
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (ones > n / 2 || zeros > n / 2) break;
                if (num & (1 << i)) ++ones;
                else ++zeros;
            }
            if (ones > zeros) res |= (1 << i);
        }
        return res;
    }
};
// @lc code=end

