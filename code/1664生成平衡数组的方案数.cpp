/*
 * @lc app=leetcode.cn id=1664 lang=cpp
 *
 * [1664] 生成平衡数组的方案数
 */

// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0;
        int l_odd = 0, r_odd = 0, sum_odd = 0;
        int l_even = 0, r_even = 0, sum_even = 0;

        int N = nums.size();

        for(int i=0;i<N;i++){
            if(i%2 == 1) sum_odd += nums[i];
            else sum_even += nums[i];
        }
        for(int i=0;i<N;i++){
            if(i%2 == 1){
                r_even = sum_odd - l_odd - nums[i];
                r_odd = sum_even - l_even;
                if((l_even+r_even) == (l_odd+r_odd)) ans ++;
                l_odd += nums[i];
            }
            else{
                r_even = sum_odd - l_odd;
                r_odd = sum_even - l_even - nums[i];
                if((l_even+r_even) == (l_odd+r_odd)) ans ++;
                l_even += nums[i];
            }
        }

        return ans;

    }
};
// @lc code=end

