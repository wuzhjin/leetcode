/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (62.62%)
 * Likes:    455
 * Dislikes: 0
 * Total Accepted:    89.2K
 * Total Submissions: 137.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // ListNode *dummy = new ListNode(-1), *pre = dummy;
        // dummy->next = head;
        // while (pre->next && pre->next->next) {
        //     ListNode *t = pre->next->next;
        //     pre->next->next = t->next;
        //     t->next = pre->next;
        //     pre->next = t;
        //     pre = t->next;
        // }
        // return dummy->next;
        if (!head || !head->next) return head;
        ListNode *t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};
// @lc code=end

