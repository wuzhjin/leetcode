/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (53.50%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    35.4K
 * Total Submissions: 61.7K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        // if (!head) return head;
        // ListNode *dummy = new ListNode(-1);
        // ListNode *newDummy = new ListNode(-1);
        // dummy->next = head;
        // ListNode *cur = dummy, *p = newDummy;
        // while (cur->next) {
        //     if (cur->next->val < x) {
        //         p->next = cur->next;
        //         p = p->next;
        //         cur->next = cur->next->next;
        //         p->next = nullptr;
        //     } else {
        //         cur = cur->next;
        //     }
        // }
        // p->next = dummy->next;
        // return newDummy->next;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (pre->next && pre->next->val < x) pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

