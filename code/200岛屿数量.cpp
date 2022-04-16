/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    vector<vector<bool> >vis;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(!vis[r][c] || grid[r][c] == '0') return;
        vis[r][c] = false;
        int r0, c0;
        for(int i=0;i<4;i++){
            r0 = r+dr[i];
            c0 = c+dc[i];
            if(r0<0 || r0>=grid.size() || c0<0 || c0>=grid[0].size()) continue;
            if(!vis[r0][c0] || grid[r0][c0] == '0') continue;
            dfs(grid, r0, c0);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int r = grid.size();
        int c = grid[0].size();
        vis.resize(r, {});
        for(auto &item: vis){
            item.resize(c, true);
        }
        int ans = 0;
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(!vis[i][j] || grid[i][j] == '0') continue;
            dfs(grid, i, j);
            ans ++;
        }
        return ans;
    }
};
// @lc code=end

