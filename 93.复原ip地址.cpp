/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.60%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    40.9K
 * Total Submissions: 87.7K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 0, "", res);
        return res;
    }
    void helper(string s, int n, string out, vector<string>& res) {
        if (n == 4) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int i = 1; i < 4; ++i) {
                if (s.size() < i) break;
                int val = atoi(s.substr(0, i).c_str());
                if (val > 255 || i != std::to_string(val).size()) continue;
                helper(s.substr(i), n + 1, out + s.substr(0, i) + (n == 3 ? "" : "."), res);
            }
        }
    }
};
// @lc code=end

