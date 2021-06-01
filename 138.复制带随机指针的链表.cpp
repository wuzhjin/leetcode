/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (55.68%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 121.1K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random
 * ，该指针可以指向链表中的任何节点或空节点。
 *
 * 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新
 * 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和
 * random
 * 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点
 * 。
 *
 * 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y
 * 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random
 * --> y 。
 *
 * 返回复制链表的头节点。
 *
 * 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val,
 * random_index] 表示：
 *
 *
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 *
 *
 * 你的代码 只 接受原链表的头节点 head 作为传入参数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 *
 * 示例 4：
 *
 *
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10000
 * Node.random 为空（null）或指向链表中的节点。
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  unordered_map<Node*, Node*> visited;
  Node* copyRandomList(Node* head) {
    // *** case 1: copy val. ***
    // if (head == nullptr)
    //   return nullptr;

    // if (visited.find(head) != visited.end())
    //   return visited[head];

    // Node* node = new Node(head->val);
    // visited[head] = node;
    // node->next = copyRandomList(head->next);
    // node->random = copyRandomList(head->random);

    // return node;

    // *** case 2: copy random and next. ***
    // if (head == nullptr)
    //   return nullptr;
    // Node* p = head;
    // while (p != nullptr) {
    //   Node* subNode;

    //   if (visited.find(p) == visited.end()) {
    //     subNode = new Node(p->val);
    //     visited[p] = subNode;
    //   } else {
    //     subNode = visited[p];
    //   }

    //   if (p->random != nullptr) {
    //     if (visited.find(p->random) == visited.end()) {
    //       Node* node = new Node(p->random->val);
    //       visited[p->random] = node;
    //       subNode->random = node;
    //     } else {
    //       subNode->random = visited[p->random];
    //     }
    //   } else {
    //     subNode->random = nullptr;
    //   }

    //   if (p->next != nullptr) {
    //     if (visited.find(p->next) == visited.end()) {
    //       Node* node = new Node(p->next->val);
    //       visited[p->next] = node;
    //       subNode->next = node;
    //     } else {
    //       subNode->next = visited[p->next];
    //     }
    //   } else {
    //     subNode->next = nullptr;
    //   }

    //   p = p->next;
    // }
    // return visited[head];

    // *** case 3: copy itself. ***
    if (head == nullptr)
      return nullptr;

    Node* p = head;

    while (p != nullptr) {
      Node* node = new Node(p->val);
      node->next = p->next;
      p->next = node;
      p = p->next->next;
    }

    p = head;
    while (p != nullptr) {
      p->next->random = p->random != nullptr ? p->random->next : nullptr;
      p = p->next->next;
    }

    Node* p_old = head;
    Node* p_new = head->next;
    Node* ans = head->next;

    while (p_old != nullptr) {
      p_old->next = p_old->next->next;
      p_new->next = p_new->next != nullptr ? p_new->next->next : nullptr;
      p_old = p_old->next;
      p_new = p_new->next;
    }
    return ans;
  }
};
// @lc code=end
