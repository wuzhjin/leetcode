import java.util.ArrayList;
import java.util.List;

import javax.swing.tree.TreeNode;

import sun.util.locale.provider.HostLocaleProviderAdapter;

/*
 * @lc app=leetcode.cn id=783 lang=java
 *
 * [783] 二叉搜索树节点最小距离
 *
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (53.14%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 27K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * 给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: root = [4,2,6,1,3,null,null]
 * 输出: 1
 * 解释:
 * 注意，root是树节点对象(TreeNode object)，而不是数组。
 * 
 * 给定的树 [4,2,6,1,3,null,null] 可表示为下图:
 * 
 * ⁠         4
 * ⁠       /   \
 * ⁠     2      6
 * ⁠    / \    
 * ⁠   1   3  
 * 
 * 最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 二叉树的大小范围在 2 到 100。
 * 二叉树总是有效的，每个节点的值都是整数，且不重复。
 * 本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * 相同
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private Integer pre, ans;

    public int minDiffInBST(TreeNode root) {
        pre = null;
        ans = Integer.MAX_VALUE;
        helper(root);
        return ans;
    }

    public void helper(TreeNode node) {
        if (node == null) return;
        helper(node.left);
        if (pre != null) {
            ans = Math.min(ans, node.val - pre);
        }
        pre = node.val;
        helper(node.right);
    }
}
// @lc code=end

