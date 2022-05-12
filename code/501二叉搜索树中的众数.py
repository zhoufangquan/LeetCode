#
# @lc app=leetcode.cn id=501 lang=python3
#
# [501] 二叉搜索树中的众数
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def findMode(self, root: TreeNode) -> List[int]:
        dic = {}

        def dfs(root, dic):
            if root is None: return

            dfs(root.left, dic)
            if root.val in dic:
                dic[root.val] += 1
            else:
                dic[root.val] = 1
            dfs(root.right, dic)         
               
        dfs(root, dic)
        ans = []
        max_f = max(dic.values())
        for k, v in dic.items():
            if v == max_f:
                ans.append(k)
        return ans


# @lc code=end

