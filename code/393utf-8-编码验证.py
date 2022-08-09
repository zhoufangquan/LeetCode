#
# @lc app=leetcode.cn id=393 lang=python3
#
# [393] UTF-8 编码验证
#

# @lc code=start
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        def f(data, s, e):  # (s, e)
            if e>len(data): return False
            for i in range(s+1, e):
                if (data[i]>>6) != 0b10:
                    return False
            return True

        i = 0
        n = len(data)

        while i<n:
            byte = data[i]
            if (byte >> 3) == 0b11110:
                if not f(data, i, i+4): return False
                i = i+4
            elif (byte >> 4) == 0b1110:
                if not f(data, i, i+3): return False
                i = i+3
            elif (byte >> 5) == 0b110:
                if  not f(data, i, i+2): return False
                i = i+2
            elif (byte >> 7) == 0:
                i = i+1
            else:
                return False
        
        return True
# @lc code=end

