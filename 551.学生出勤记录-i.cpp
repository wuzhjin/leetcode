/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 *
 * https://leetcode-cn.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (49.40%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 27.3K
 * Testcase Example:  '"PPALLP"'
 *
 * 给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：
 * 
 * 
 * 'A' : Absent，缺勤
 * 'L' : Late，迟到
 * 'P' : Present，到场
 * 
 * 
 * 如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
 * 
 * 你需要根据这个学生的出勤记录判断他是否会被奖赏。
 * 
 * 示例 1:
 * 
 * 输入: "PPALLP"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 输入: "PPALLL"
 * 输出: False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, cntL = 0;
        for (char c : s) {
            if (c == 'A') {
                if (++cntA > 1) return false;
                cntL = 0;
            } else if (c == 'L') {
                if (++cntL > 2) return false;
            } else {
                cntL = 0;
            }
        }
        return true;
    }
};
// @lc code=end

