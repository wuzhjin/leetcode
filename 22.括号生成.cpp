/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.15%)
 * Likes:    834
 * Dislikes: 0
 * Total Accepted:    93.3K
 * Total Submissions: 126.5K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // vector<string> res;
        // generateParenthesisDFS(n, n, "", res);
        // return res;   
        unordered_set<string> st;
        if (n == 0) st.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        st.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + "(", res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ")", res);
        }
    }
};
// @lc code=end

