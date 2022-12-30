/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n+1, 0ll);
        if(s[0] == '*') dp[1] = 9ll;
        else if(s[0] != '0') dp[1] = 1ll;
        else dp[1] = 0ll;
        dp[0] = 1ll;
        long long mod = 1000000007ll;
        for(int i=2;i<=n;i++){
            if('7' <=s[i-1] && s[i-1] <= '9'){
                if(s[i-2] == '1') dp[i] = dp[i-1] + dp[i-2];
                else if(s[i-2] == '*') dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1];
            }
            else if('1' <=s[i-1] && s[i-1] <= '6'){
                if(s[i-2] == '1' || s[i-2] == '2') dp[i] = dp[i-1] + dp[i-2];
                else if(s[i-2] == '*') dp[i] = dp[i-1] + 2*dp[i-2];
                else dp[i] = dp[i-1];
            }
            else if(s[i-1] == '0'){
                if(s[i-2] == '1' || s[i-2] == '2') dp[i] = dp[i-2];
                else if(s[i-2] == '*') dp[i] = 2*dp[i-2];
                else dp[i] = 0;
            }
            else{
                if(s[i-2] == '1') dp[i] = 9*dp[i-1] + 9*dp[i-2];
                else if(s[i-2] == '2') dp[i] = 9*dp[i-1] + 6*dp[i-2];
                else if(s[i-2] == '*') dp[i] = 9*dp[i-1] + 15*dp[i-2];
                else dp[i] = 9*dp[i-1];                
            }

            dp[i] = dp[i]%mod;
        }

        return dp[n];
    }
};
// @lc code=end

