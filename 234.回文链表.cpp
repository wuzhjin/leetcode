/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (39.00%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    69.6K
 * Total Submissions: 170.4K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
         /* 方法一：快慢指针找到链表中点，使用stack，若为奇数，即fast->next为空，慢指针退1*/
        // stack<int> st{{head->val}};
        // ListNode *slow = head, *fast = head;
        // while (fast->next && fast->next->next) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     st.push(slow->val);
        // }
        // if (!fast->next) st.pop();
        // while (slow->next) {
        //     slow = slow->next;
        //     int tmp = st.top(); st.pop();
        //     if (tmp != slow->val) return false;
        // }
        // return true;

        /* 方法二：O(1)空间，不使用栈，将中点后的链表翻转比较 */
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        while (slow->next) {
            slow = slow->next;
            if (slow->val != pre->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end

