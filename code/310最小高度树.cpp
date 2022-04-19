/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    vector<vector<int> > G;  // 0 -> 1 2 3 4 5
    vector<int> res;
    bool vis[100005];

    pair<int, int> bfs(vector<vector<int> > G, int s){
        pair<int, int> ans = {s, 0};
        queue<pair<int, int>> Q;
        Q.push(ans);
        vis[s] = false;

        while(!Q.empty()){
            auto temp = Q.front(); Q.pop();
            if(temp.second > ans.second){
                ans = temp;
            }
            int u = temp.first;
            for(int i=0;i<G[u].size();i++){
                int v = G[u][i];
                if(!vis[v]) continue;
                Q.push({v, temp.second+1});
                vis[v] = false;
            }
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        G.resize(n);
        for(auto &item: edges){
            G[item[0]].push_back(item[1]);
            G[item[1]].push_back(item[0]);
        }
        memset(vis, true, sizeof(vis));
        pair<int, int> temp = bfs(G, 1);
        
        memset(vis, true, sizeof(vis));
        pair<int, int> temp = bfs(G, temp.first);

        dfs(G, );

        return res;
    }
};
// @lc code=end

int main(){
    

    return 0;
}