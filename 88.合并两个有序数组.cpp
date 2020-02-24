/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.63%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    111.2K
 * Total Submissions: 238.2K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\j[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], i = 3
 * nums2 = [2,5,6],       j = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n-1,i=m-1,j=n-1;
        while(i>=0&&j>=0)
        {
            nums1[len--]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
        }
        if(i>=0)
        {
            return;
        }
        while(j>=0)
        {
            nums1[len--]=nums2[j--];
        }
        return;
    }
};
// @lc code=end

