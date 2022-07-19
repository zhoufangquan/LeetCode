/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.length();

        // 回文串的长度是奇数
        for(int i=0;i<s.length();i++){
            int l = i-1;
            int r = i+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                ans ++;
                l--;
                r++;
            }
        }

        // 回文串的长度是偶数
        for(int i=0;i<s.length()-1;i++){
            if(s[i] != s[i+1]) continue;
            int l = i;
            int r = i+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                ans ++;
                l--;
                r++;
            }
        }

        return ans;
    }
};
// @lc code=end

int main(){

    Solution test;
    string s;
    cin>>s;
    cout<<test.countSubstrings(s);

    return 0;
}