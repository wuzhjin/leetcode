import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=720 lang=java
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
    public String longestWord(String[] words) {
        // String ans = "";
        // Set<String> wordsSet = new HashSet<>();
        // for (String word : words) wordsSet.add(word);
        // for (String word : words) {
        //     if (word.length() > ans.length() ||
        //     (word.length() == ans.length() && word.compareTo(ans) < 0)) {
        //         boolean good = true;
        //         for (int k = 1; k < word.length(); ++k) {
        //             if (!wordsSet.contains(word.substring(0, k))) {
        //                 good = false;
        //                 break;
        //             }
        //         }
        //         if (good) ans = word;
        //     }
        // }
        // return ans;

        String ans = "";
        Set<String> wordsSet = new HashSet<>();
        Arrays.sort(words);
        for (String word : words) {
            if (word.length() == 1 || wordsSet.contains(word.substring(0, word.length() - 1))) {
                ans = (word.length() > ans.length()) ? word : ans;
                wordsSet.add(word);
            }
        }
        return ans;
    }
}
// @lc code=end

