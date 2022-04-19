/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include "HF.h"
// @lc code=start
class Solution
{
public:
    vector<vector<int>> G; // 0 -> 1 2 3 4 5
    vector<int> res;
    bool vis[100005];
    int e[100005]; // 记录连通图的每个节点的离心率
    int bfs(vector<vector<int>> G, int s)
    {
        pair<int, int> ans = {s, 1};
        queue<pair<int, int>> Q;
        Q.push(ans);
        vis[s] = false;
        e[s] = max(e[s], 1);

        while (!Q.empty())
        {
            auto temp = Q.front();
            Q.pop();
            e[temp.first] = max(e[temp.first], temp.second);
            if (temp.second > ans.second)
            {
                ans = temp;
            }
            int u = temp.first;
            for (int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                if (!vis[v])
                    continue;
                Q.push({v, temp.second + 1});
                vis[v] = false;
            }
        }
        return ans.first;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        G.resize(n);
        for (auto &item : edges)
        {
            G[item[0]].push_back(item[1]);
            G[item[1]].push_back(item[0]);
        }
        memset(e, 0, sizeof(e));
        memset(vis, true, sizeof(vis));
        int end_p = bfs(G, 0);

        memset(vis, true, sizeof(vis));
        end_p = bfs(G, end_p);
        memset(vis, true, sizeof(vis));
        end_p = bfs(G, end_p);

        int min_e = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            min_e = min(min_e, e[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (e[i] == min_e)
                res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

int main()
{

    return 0;
}

/*
6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]


*/