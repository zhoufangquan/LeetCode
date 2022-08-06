/*
 * @lc app=leetcode.cn id=1414 lang=cpp
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int ans = 0;
        int par[44];
        par[0] = par[1] = 1;
        for(int i=2;i<44;i++){
            par[i] = par[i-1] + par[i-2];
            // cout<<par[i]<<'\n';
        }
        
        int idx = 43;
        while(idx>0 && par[idx] > k) idx--;
        while(k>0){
            if(k>=par[idx]){
                // cout<<k<<'-'<<par[idx]<<'\n';
                k -= par[idx];
                ans ++;
            }
            if(idx != 0) idx--;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution test;
    cout<<test.findMinFibonacciNumbers(19)<<'\n';
    return 0;
}