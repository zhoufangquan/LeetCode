/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include "HF.h"
// @lc code=start
class Solution
{
public:
    int n, m;
    vector<vector<int>> pre;
    vector<vector<int>> dp;
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        n = matrix.size();
        if (n == 0)
            return 0;
        m = matrix[0].size();
        pre.resize(n, {});
        dp.resize(n, {});
        for (auto &item : pre)
            item.resize(m, 0);
        for (auto &item : dp)
            item.resize(m, 0);
            
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pre[i][j] = matrix[i][j] - '0';
        
        for (int i = 1; i < n; i++)
            pre[i][0] += pre[i - 1][0];
        for (int j = 1; j < m; j++)
            pre[0][j] += pre[0][j - 1];

        for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + (matrix[i][j] - '0');
        }

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(matrix[i][j] == '0') dp[i][j] = 0;
            else{
                
            }
        }


        int ans = 0;
    }
};
// @lc code=end

int main()
{

    return 0;
}