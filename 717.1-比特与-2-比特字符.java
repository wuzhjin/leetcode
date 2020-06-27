/*
 * @lc app=leetcode.cn id=717 lang=java
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length, i = 0;
        while (i < n - 1) {
            if (bits[i] == 0) {
                ++i;
            } else {
                i += 2;
            }
        }
        return i == n - 1;
    }
}
// @lc code=end

