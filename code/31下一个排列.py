#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#
from utils import str2arr
# @lc code=start
class Solution:
    def nextPermutation(self, nums) -> None:
        if len(nums) == 1: return 
        id = len(nums)-1
        for i in range(len(nums)-1, 0, -1):
            id -= 1
            if nums[i] > nums[i-1]:
                break
        if nums[id] > nums[id+1]:
            nums.reverse()
            return
        nums[id+1:] = nums[-1:id:-1]
        for i in range(id+1, len(nums)):
            if nums[id] < nums[i]:
                nums[i], nums[id] = nums[id], nums[i]
                break
        
# @lc code=end

data = input()
data = str2arr.get_array(data)

test = Solution()
test.nextPermutation(data)

print(data)