nums = input().split()
SUM = int(input())
opts = ['+', '-', '']

ans = []

def dfs(nums, dep, SUM, s, ans):
    s += nums[dep]
    if dep == 4:
        if eval(s) == SUM:
            ans.append(s)
        return
    
    for opt in opts:
        dfs(nums, dep+1, SUM, s+opt, ans)
s = ''
dfs(nums, 0, SUM, s, ans)
print(ans)