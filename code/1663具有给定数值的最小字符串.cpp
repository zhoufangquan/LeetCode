/*
 * @lc app=leetcode.cn id=1663 lang=cpp
 *
 * [1663] 具有给定数值的最小字符串
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        k -= n;
        while(k>=26){
            ans += 'z';
            n -= 1;
            k -= 25;
        }
        if(n > 0) ans += ('a' + k );
        while(n>1) ans += 'a', n--;

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

