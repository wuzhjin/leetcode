/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.85%)
 * Likes:    624
 * Dislikes: 0
 * Total Accepted:    97.1K
 * Total Submissions: 193.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left,root->right);


        // if(!root) return true;
        // queue<TreeNode*> que1,que2;
        // que1.push(root->left);
        // que2.push(root->right);
        // while(!que1.empty()&&!que2.empty())
        // {
        //     TreeNode* node1=que1.front();que1.pop();
        //     TreeNode* node2=que2.front();que2.pop();
        //     if(!node1&&!node2) continue;
        //     if((!node1&&node2)||(node1&&!node2)) return false;
        //     if(node1->val!=node2->val) return false;
        //     que1.push(node1->left);que1.push(node1->right);
        //     que2.push(node2->right);que2.push(node2->left);
        // }
        // return true;
    }
    bool isSymmetric(TreeNode* left,TreeNode* right)
    {
        if(!left&&!right) return true;
        if((!left&&right)||(left&&!right)||(left->val!=right->val))
        {
            return false;
        }
        return isSymmetric(left->left,right->right)&&isSymmetric(left->right,right->left);
    }
};
// @lc code=end

