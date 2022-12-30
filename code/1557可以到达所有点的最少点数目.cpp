/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> du(n, 0);
        for (int i=-0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            du[v] ++;
        }
        vector<int> ans;
        for(int i=0;i<du.size();i++){
            if (du[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end

