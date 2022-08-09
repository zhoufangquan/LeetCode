#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        d_in = [0]*numCourses
        edges = [[] for _ in range(numCourses)]
        for u, v in prerequisites:
            d_in[u] += 1
            edges[v].append(u)
        
        d_in_zero = [id for id, d in enumerate(d_in) if d == 0]

        while len(d_in_zero) > 0:
            u = d_in_zero.pop()
            for v in edges[u]:
                d_in[v] -= 1
                if d_in[v] == 0:
                    d_in_zero.append(v)
            numCourses -= 1
    
        return numCourses == 0

# @lc code=end
