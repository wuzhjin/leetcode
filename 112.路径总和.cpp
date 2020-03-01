/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (48.20%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    53.4K
 * Total Submissions: 108.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    bool hasPathSum(TreeNode* root, int sum) {
        // if(!root) return false;
        // int res=root->val;
        // if(!root->left&&!root->right&&sum==res) return true;
        // return hasPathSum(root->left,sum-res)||hasPathSum(root->right,sum-res);
        if(!root) return false;
        stack<TreeNode*> s{{root}};
        while(!s.empty())
        {
            TreeNode* t=s.top();s.pop();
            if(!t->left&&!t->right&&t->val==sum) return true;
            if(t->left)
            {
                t->left->val+=t->val;
                s.push(t->left);
            } 
            if(t->right) 
            {
                t->right->val+=t->val;
                s.push(t->right);
            }
        }
        return false;
    }
};
// @lc code=end

