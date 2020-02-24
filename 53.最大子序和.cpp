/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (47.87%)
 * Likes:    1630
 * Dislikes: 0
 * Total Accepted:    161.2K
 * Total Submissions: 327.6K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 *
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //int allMax=nums[0],cur=nums[0];
        //for(int i=1;i<nums.size();++i)
        //{
        //    //if(cur<0) cur=nums[i];
        //    //else cur=cur+nums[i];
        //    //if(allMax<cur) allMax=cur;
        //    cur=max(nums[i],cur+nums[i]);
        //    allMax=max(cur,allMax);
        //}
        //return allMax;
        if(nums.empty()) return 0;
        int len=nums.size();
        return helper(nums,0,len-1);
    }
    int helper(vector<int>& nums,int left,int right){
        if(left>=right) return nums[left];
        int mid=(left+right)/2;
        int leftMax=helper(nums,left,mid-1);
        int rightMax=helper(nums,mid+1,right);
        int midMax=nums[mid];
        int curMax=midMax;
        for(int i=mid+1;i<=right;++i){
            curMax+=nums[i];
            midMax=max(midMax,curMax);
        }
        curMax=midMax;
        for(int i=mid-1;i>=left;--i){
            curMax+=nums[i];
            midMax=max(midMax,curMax);
        }
        return max(midMax,max(leftMax,rightMax));
    }
};
// @lc code=end

