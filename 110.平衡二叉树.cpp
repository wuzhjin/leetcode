/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (49.16%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    51.9K
 * Total Submissions: 103K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // if(!root) return true;
        // if(abs(getDepth(root->left)-getDepth(root->right))>1) return false;
        // return isBalanced(root->left)&&isBalanced(root->right);
        if (checkDepth(root)==-1) return false;
        else return true;
    }
    int checkDepth(TreeNode* node)
    {
        if(!node) return 0;
        int left=checkDepth(node->left);
        if(left==-1) return -1;
        int right=checkDepth(node->right);
        if(right==-1) return -1;
        int dif=abs(left-right);
        if(dif>1) return -1;
        else return 1+max(left,right);
    }
    int getDepth(TreeNode* node)
    {
        if(!node) return 0;
        return 1+max(getDepth(node->left),getDepth(node->right));
    }
};
// @lc code=end

