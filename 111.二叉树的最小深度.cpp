/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.45%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 127.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    int minDepth(TreeNode* root) {
        // if(!root) return 0;
        // if(!root->left) return 1+minDepth(root->right);
        // if(!root->right) return 1+minDepth(root->left);
        // return 1+min(minDepth(root->left),minDepth(root->right));
        if(!root) return 0;
        queue<TreeNode*> que{{root}};
        int res=0;
        while(!que.empty())
        {
            ++res;
            for(int i=(int)que.size();i>0;--i)
            {
                TreeNode* cur=que.front();que.pop();
                if(!cur->left&&!cur->right) return res;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return -1;
    }
};
// @lc code=end

