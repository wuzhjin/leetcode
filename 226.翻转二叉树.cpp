/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (72.39%)
 * Likes:    384
 * Dislikes: 0
 * Total Accepted:    59.3K
 * Total Submissions: 79.8K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
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
    TreeNode* invertTree(TreeNode* root) {
        /*递归，都要交换*/
        // if (!root) return nullptr;
        // TreeNode* tmp = root->left;
        // root->left = invertTree(root->right);
        // root->right = invertTree(tmp);
        // return root;

        /*迭代，层序遍历*/
        if (!root) return nullptr;
        queue<TreeNode*> que{{ root }};
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        return root;
    }
};
// @lc code=end

