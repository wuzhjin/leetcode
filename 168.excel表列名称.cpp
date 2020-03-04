/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (35.29%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    20.5K
 * Total Submissions: 55.7K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while (n) {
            char ch ='A' + --n % 26;
            str.insert(str.begin(), ch);
            n /= 26;
        }
        return str;
//        string str = "";
//        while (n) {
//            if (n % 26 == 0) {
//                str.insert(str.begin(), 'Z');
//                n -= 26;
//            }
//            else {
//                str.insert(str.begin(), 'A' + n % 26 -1);
//                n -= n % 26;
//            }
//            n /= 26;
//        }
//        return str;
    }
};
// @lc code=end

