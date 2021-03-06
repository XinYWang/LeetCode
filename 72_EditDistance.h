/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
// Solution: Dynamic Programming
//   Ø r o s
// Ø 0 1 2 3
// h 1 1 2 3
// o 2 2 1 2
// r 3 2 2 2
// s 4 3 3 2
// e 5 4 4 3
// rule:
// if word1[i - 1] == word2[j - 1], dp[i][j] = dp[i - 1][j - 1]
// else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int dp[len1 + 1][len2 + 1];
        for(int i = 0; i <= len1; i++)
            dp[i][0] = i;
        for(int j = 0; j <= len2; j++)
            dp[0][j] = j;
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <= len2; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        return dp[len1][len2];
    }
};
