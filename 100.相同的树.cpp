/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (55.39%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    63.3K
 * Total Submissions: 111.8K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //*****递归******
        if(q==nullptr&&p==nullptr) return true;
        if((p==nullptr&&q)||(p&&q==nullptr)||(p->val!=q->val)) return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
        //*****先序遍历******
//        stack<TreeNode*> st;
//        st.push(p);
//        st.push(q);
//        while(!st.empty())
//        {
//            p=st.top();st.pop();
//            q=st.top();st.pop();
//            if(!p&&!q) continue;
//            if((!p&&q)||(p&&!q)||(p->val!=q->val)) return false;
//            st.push(q->right);st.push(p->right);
//            st.push(q->left);st.push(p->left);
//        }
//        return true;

        ///*****中序遍历******
//        stack<TreeNode*> st;
//        while(p||q||!st.empty())
//        {
//            while(p||q)
//            {
//                if((!p&&q)||(p&&!q)||(p->val!=q->val)) return false;
//                st.push(p);
//                st.push(q);
//                p=p->left;
//                q=q->left;
//            }
//            p=st.top();st.pop();
//            q=st.top();st.pop();
//            p=p->right;
//            q=q->right;
//        }
//        return true;

        ///*****后序遍历******
        
        ///*****层序遍历******
//        queue<TreeNode*> que;
//        que.push(p);
//        que.push(q);
//        while(!que.empty())
//        {
//            p=que.front();que.pop();
//            q=que.front();que.pop();
//            if(!q&&!p) continue;
//            if((!q&&p)||(q&&!p)||(q->val!=p->val)) return false;
//            que.push(p->left);
//            que.push(q->left);
//            que.push(p->right);
//            que.push(q->right);
//        }
//        return true;
    }
};
// @lc code=end

