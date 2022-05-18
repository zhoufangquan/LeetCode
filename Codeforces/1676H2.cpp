#include <bits/stdc++.h>

using namespace std;

int arr[400005];

int solve_segmentTree(int n)
{
    return 0;
}


long long solve_merge(int n)
{
    int len = 1;
    long long ans = 0;
    for (; len <= n; len *= 2)
    {
        for (int l = 1; l <= n; l += 2 * len)
        {
            int i = l + len - 1;
            int j = min(l + 2 * len - 1, n);
            if (i == n)
                continue;
            while (i >= l && j >= l + len)
            {
                if (arr[i] >= arr[j])
                {
                    ans += (long long)(j - l - len) + (long long)1;
                    i--;
                }
                else
                {
                    j--;
                }
            }
            i = l + len - 1;
            j = min(l + 2 * len - 1, n);
            stack<int> temp;
            while (i >= l && j >= l + len)
            {

                if (arr[i] >= arr[j])
                {
                    temp.push(arr[i]);
                    i--;
                }
                else
                {
                    temp.push(arr[j]);
                    j--;
                }
            }
            while (i >= l)
            {
                temp.push(arr[i]);
                i--;
            }
            while (j >= l + len)
            {
                temp.push(arr[j]);
                j--;
            }

            i = l;
            while (!temp.empty())
                arr[i++] = temp.top(), temp.pop();
        }
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", arr + i);
        }
        long long ans = solve_merge(n);
        cout << ans << '\n';
    }
    return 0;
}