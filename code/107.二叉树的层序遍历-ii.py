#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层序遍历 II
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
    def levelOrderBottom(self, root: TreeNode):
        ans = []
        if root is None: return ans
        Q = []
        Q.append([root, 0])

        while len(Q) > 0:
            temp = Q.pop(0)
            if temp[1]+1 > len(ans):
                ans.append([])
            ans[temp[1]].append(temp[0].val)

            if temp[0].left is not None:
                Q.append([temp[0].left, temp[1]+1])
            if temp[0].right is not None:
                Q.append([temp[0].right, temp[1]+1])
        
        return ans[::-1]
# @lc code=end

data = input()
root = get_tree(data)
test = Solution()
res = test.levelOrderBottom(root)
print(res)
for i in res:
    print(i)

