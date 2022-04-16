#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
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
    def levelOrder(self, root: TreeNode):
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
        
        return ans
# @lc code=end


if __name__ == '__main__':
    data = input()
    root = get_tree(data)
    test = Solution()
    res = test.levelOrder(root)

    for i in res:
        print(i)