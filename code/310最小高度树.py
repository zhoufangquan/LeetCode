#
# @lc app=leetcode.cn id=310 lang=python3
#
# [310] 最小高度树
#
from utils.str2arr import *
# @lc code=start
class Solution:
    def findMinHeightTrees(self, n: int, edges):
        def bfs(G, s):
            ans = [s, 1]
            Q = []
            Q.append(ans)
            vis[s] = False
            e[s] = max(e[s], 1)

            while len(Q) > 0:
                temp = Q.pop(0)
                e[temp[0]] = max(e[temp[0]], temp[1])
                if temp[1] > ans[1]:
                    ans = temp[:]
                u = temp[0]

                for v in G[u]:
                    if not vis[v]: continue
                    Q.append([v, temp[1]+1])
                    vis[v] = False
            return ans[0]

        e = [0]*n
        vis = [True]*n
        G = [[] for _ in range(n)]
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)

        end_p = bfs(G, 0)

        vis = [True]*n
        end_p = bfs(G, end_p)

        vis = [True]*n
        end_p = bfs(G, end_p)

        min_e = min(e)
        res = []
        for i, item in enumerate(e):
            if min_e == item:
                res.append(i)
        return res


# @lc code=end


n = int(input())
data = input()

edges = get_array(data)

test = Solution()
ans = test.findMinHeightTrees(n, edges=edges)

print(ans)