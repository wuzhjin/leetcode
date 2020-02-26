/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (62.94%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    42.2K
 * Total Submissions: 65.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // if(!root) return {};
        // vector<vector<int>> res;
        // queue<TreeNode*> que{{root}};
        // while(!que.empty())
        // {
        //     vector<int> tmp;
        //     for(int i=que.size();i>0;--i)
        //     {
        //         TreeNode* t=que.front();que.pop();
        //         tmp.push_back(t->val);
        //         if(t->left) que.push(t->left);
        //         if(t->right) que.push(t->right);
        //     }
        //     res.insert(res.begin(),tmp);
        //     tmp.clear();
        // }
        // return res;
        if(!root) return {};
        vector<vector<int>> res;
        levelOrderBottom(root,0,res);
        return vector<vector<int>> (res.rbegin(),res.rend());
    }
    void levelOrderBottom(TreeNode* node,int level,vector<vector<int>>& res)
    {
        if(!node) return; 
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelOrderBottom(node->left,level+1,res);
        if(node->right) levelOrderBottom(node->right,level+1,res);
    }
};
// @lc code=end

