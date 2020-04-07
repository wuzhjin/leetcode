/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (63.11%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 26.1K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其层序遍历:
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总数不会超过 5000。
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            vector<int> out;
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front(); q.pop();
                out.push_back(t->val);
                if (!t->children.empty()) {
                    for (auto a : t->children) {
                        q.push(a);
                     }
                }
            }
            res.push_back(out);
        } 
        return res;
    }
};
// @lc code=end

