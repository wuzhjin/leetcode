/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (42.76%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 27K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    // vector<int> findMode(TreeNode* root) {
    //     vector<int> res;
    //     int mx = 0, cnt = 1;
    //     TreeNode *pre = nullptr;
    //     inorder(root, pre, cnt, mx, res);
    //     return res;
    // }
    // void inorder(TreeNode *node, TreeNode*& pre, int& cnt, int& mx, vector<int>& res) {
    //     if (!node) return;
    //     inorder(node->left, pre, cnt, mx, res);
    //     if (pre) {
    //         cnt = (node->val == pre->val) ? cnt + 1 : 1;
    //     }
    //     if (cnt >= mx) {
    //         if (cnt > mx) res.clear();
    //         res.push_back(node->val);
    //         mx = cnt;
    //     }
    //     pre = node;
    //     inorder(node->right, pre, cnt, mx, res);
    // }
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        TreeNode *p = root, *pre = nullptr;
        stack<TreeNode*> s;
        int mx = 0, cnt = 1;
        while (!s.empty() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (pre) {
                cnt = (p->val == pre->val) ? cnt + 1 : 1;
            }
            if (cnt >= mx) {
                if (cnt > mx) res.clear();
                res.push_back(p->val);
                mx = cnt;
            }
            pre = p;
            p = p->right;
        }
        return res;
    }
};
// @lc code=end

