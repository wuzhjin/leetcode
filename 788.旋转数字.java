import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=788 lang=java
 *
 * [788] 旋转数字
 *
 * https://leetcode-cn.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (60.08%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 19.2K
 * Testcase Example:  '10'
 *
 * 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
 * 
 * 如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5
 * 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9
 * 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
 * 
 * 现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 
 * 在[1, 10]中有四个好数： 2, 5, 6, 9。
 * 注意 1 和 10 不是好数, 因为他们在旋转之后不变。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * N 的取值范围是 [1, 10000]。
 * 
 * 
 */

// @lc code=start
class Solution {
    public int rotatedDigits(int N) {
        // int ans = 0;
        // for (int i = 1; i <= N; ++i) {
        //     if (check(i)) ++ans;
        // }
        // return ans;
        
        int ans = 0;
        int[] dp = new int[N + 1];
        for (int i = 0; i <= N; ++i) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2; ++ans;
                }
            } else {
                int a = dp[i / 10], b = dp[i % 10];
                if (a == 1 && b == 1) dp[i] = 1;
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2; ++ans;
                }
            }
        }
        return ans;
    }

    public boolean check(int k) {
        String str = Integer.toString(k);
        boolean flag = false;
        for (char c : str.toCharArray()) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;
        }
        return flag;
    }
}
// @lc code=end

