/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.55%)
 * Likes:    4118
 * Dislikes: 0
 * Total Accepted:    414.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
 * 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 *
 *
 * 示例 4：
 *
 *
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 *
 *
 * 示例 5：
 *
 *
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0
 * 0
 * 1
 * -10^6
 *
 *
 *
 *
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 *
 */

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // case 1 : 使用获得Kth子函数（逐渐缩小搜查范围，每次淘汰 k / 2 个值）
    int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2,
        right = (m + n + 2) / 2;
    return (findKth(nums1, 0, nums2, 0, left) +
            findKth(nums1, 0, nums2, 0, right)) /
           2.0;
  }

  int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (i >= nums1.size())
      return nums2[j + k - 1];
    if (j >= nums2.size())
      return nums1[i + k - 1];
    if (k == 1)
      return min(nums1[i], nums2[j]);

    int midVal1 =
        (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 =
        (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;

    if (midVal1 < midVal2) {
      return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    } else {
      return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
  }
};
// @lc code=end
