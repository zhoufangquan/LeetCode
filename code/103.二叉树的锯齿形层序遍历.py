#
# @lc app=leetcode.cn id=103 lang=python3
#
# [103] 二叉树的锯齿形层序遍历
#
from utils.str2tree import *
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode):
        ans = []
        if root is None:
            return ans
        Q = []
        Q.append([root, 0])
        while len(Q) > 0:
            temp = Q.pop(0)
            if temp[1]+1 > len(ans):
                ans.append([])
            ans[temp[1]].append(temp[0].val)
            if temp[0].left:
                Q.append([temp[0].left, temp[1]+1])
            if temp[0].right:
                Q.append([temp[0].right, temp[1]+1])
        for i in range(1, len(ans), 2):
            ans[i] = ans[i][::-1]
        return ans
# @lc code=end

data = input()
root = get_tree(data)
test = Solution()
res = test.zigzagLevelOrder(root)
print(res)