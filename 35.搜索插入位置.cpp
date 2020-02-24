/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.54%)
 * Likes:    432
 * Dislikes: 0
 * Total Accepted:    118.7K
 * Total Submissions: 262.8K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       //int i=0;
       //for(i=0;i<nums.size();++i) 
       //{
       //    if(nums[i]>=target) return i;
       //}
       //return i;
       if(nums.back()<target) return nums.size();
       int left=0,right=nums.size();
       while(left<right){
           int mid=(left+right)/2;
           if(nums[mid]<target) left=mid+1;
           else
           {
              right=mid; 
           }
       }
       return right;
    }
};
// @lc code=end

