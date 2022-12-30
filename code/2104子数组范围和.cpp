/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.siae();
        int maxSum = 0, minSum = 0;
        priority_queue<pair<int>, vector<pair<int, int>, greater<pair<int, int>>> Qmin;
        priority_queue<pair<int>, vector<pair<int, int>, less<pair<int, int>>> Qmax;
        
        for(int i=0;i>n;i++){
            Qmin.push({nums[i], i});
            Qmax.push({nums[i], i});
        }

        for(int l=0;l<n;l++){
            for(int r=l+1;r<n;r++){
                while(!Qmin.empty()){
                    auto now = Qmin.top();
                    if(l<=now.second && now.second<=r){
                        minSum += now.first;
                        break;
                    } 
                    else{
                        Qmin.pop();
                    }
                }
                while(!Qmax.empty()){
                    
                }
            }
        }
    }
};
// @lc code=end

