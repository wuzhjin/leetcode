/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (73.40%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 30.7K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其后序遍历: [5,6,3,2,4,1].
 * 
 * 
 * 
 * 说明: 递归法很简单，你可以使用迭代法完成此题吗?
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
    vector<int> postorder(Node* root) {
        // vector<int> res;
        // helper(root, res);
        // return res;
        
        if (!root) return {};
        vector<int> res;
        stack<Node*> s{{root}};
        while (!s.empty()) {
            Node *t = s.top(); s.pop();
            res.insert(res.begin(), t->val);
            for (Node* child : t->children) {
                if (child) s.push(child);
            }
        }
        return res;
    }
    void helper(Node* node, vector<int>& res) {
        if (!node) return;
        for (Node* child : node->children) {
            helper(child, res);
        }
        res.push_back(node->val);
    }
};
// @lc code=end

