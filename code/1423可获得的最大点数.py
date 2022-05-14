#
# @lc app=leetcode.cn id=1423 lang=python3
#
# [1423] 可获得的最大点数
#

# @lc code=start
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        ans = 0
        prefix = []
        suffix = []
        for i in range(len(cardPoints)):
            if i == 0:
                prefix.append(cardPoints[i])
                suffix.append(sum(cardPoints))
            else:
                prefix.append(prefix[-1]+cardPoints[i])
                suffix.append(suffix[-1]-cardPoints[i-1])
        # print(prefix)
        # print(suffix)
        for i in range(1, k):
            ans = max(ans, prefix[i-1]+suffix[-(k-i)])
        return max(ans, prefix[k-1], suffix[-k])
# @lc code=end

