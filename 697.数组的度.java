import java.util.HashMap;
import java.util.Map;

import org.graalvm.compiler.core.match.MatchStatement;

import jdk.internal.net.http.common.Pair;

/*
 * @lc app=leetcode.cn id=697 lang=java
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (53.40%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 32.4K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1, 2, 2, 3, 1]
 * 输出: 2
 * 解释: 
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,2,3,1,4,2]
 * 输出: 6
 * 
 * 
 * 注意:
 * 
 * 
 * nums.length 在1到50,000区间范围内。
 * nums[i] 是一个在0到49,999范围内的整数。
 * 
 * 
 */

// @lc code=start
class Pair<U, V> {
    public U first;
    public V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int findShortestSubArray(final int[] nums) {
        final int n = nums.length;
        int res = Integer.MAX_VALUE, degree = 0;
        final Map<Integer, Integer> m = new HashMap<>(), startIndex = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            m.put(nums[i], m.getOrDefault(nums[i], 0) + 1);
            if (!startIndex.containsKey(nums[i])) startIndex.put(nums[i], i);
            if (m.get(nums[i]) == degree) {
                res = Math.min(res, i - startIndex.get(nums[i]) + 1);
            } else if (m.get(nums[i]) > degree) {
                res = i - startIndex.get(nums[i]) + 1;
                degree = m.get(nums[i]);
            }
        }
        return res;
    }
}
// @lc code=end

