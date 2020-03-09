/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (65.26%)
 * Likes:    825
 * Dislikes: 0
 * Total Accepted:    183.9K
 * Total Submissions: 270.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        // ListNode *pre = nullptr, *cur = head;
        // while (cur) {
        //     ListNode *t = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = t;
        // }
        // return pre;
        // ListNode *newHead = nullptr;
        // while (head) {
        //     ListNode *t = head->next;
        //     head->next = newHead;
        //     newHead = head;
        //     head = t;
        // }
        // return newHead;
        /* 递归 */
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
// @lc code=end

