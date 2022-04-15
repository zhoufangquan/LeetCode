/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */
#include"HF.h"
// @lc code=start

struct City{
    int u;
    int cost;
    int k;
};

bool cmp(City &a, City &b){
    return a.cost < b.cost;
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int res = -1;

        priority_queue<City> Q;
        vector<bool> vis(n);
        for(int i=0;i<n;i++) vis[i] = 0;
        
        Q.push({src, 0, 0}); // 输入起始点，0花费，经过0个中转站
        vis[src] = 1;
        while(!Q.empty()){
            City now = Q.top(); Q.pop();

            if(dst == now.u && now.k <= k+1){
                res = now.cost;
                break;
            }

            

        }

        return res;
    }
};
// @lc code=end

