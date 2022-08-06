/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    int dp[1003][1003];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, 0x3f, sizeof dp);
        int n = books.size(); // number of books
        dp[0][0] = 0;
        for (int i=0;i<n;i++){
            for(int j=0;j<shelfWidth;j++){
                if (books[i][0] + j > shelfWidth) continue;
                dp[i][j]
            }
        }
    }
};
// @lc code=end

