/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (42.73%)
 * Likes:    349
 * Dislikes: 0
 * Total Accepted:    62.7K
 * Total Submissions: 141.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
        /* head不可靠，可能会被删除 */
        // ListNode *dummy = new ListNode(-1), *pre = dummy;
        // dummy->next = head;
        // while (pre->next) {
        //     if (pre->next->val == val) {
        //         /* 删除节点，指向空 */
        //         ListNode *t = pre->next;
        //         pre->next = t->next;
        //         t->next = nullptr;
        //         delete t;
        //     }
        //     else {
        //         pre = pre->next;
        //     }
        // }
        // return dummy->next;
    }
};
// @lc code=end

