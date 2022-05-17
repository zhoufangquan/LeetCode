/*
有时候 [公式] 很巨大，而我们又不需要使用所有的节点，这时便可以动态开点——不再一次性建好树，
而是一边修改、查询一边建立。
我们不再用p*2和p*2+1代表左右儿子，而是用ls和rs记录左右儿子的编号。设总查询次数为 m，则这样的总空间复杂度为 O(mlog(n) 。

*/
#include<bits/stdc++.h>
using namespace std;
// MAXV一般能开多大开多大，例如内存限制128M时可以开到八百万左右
#define ls(x) tree[x].ls
#define rs(x) tree[x].rs
#define val(x) tree[x].val
#define mark(x) tree[x].mark

typedef long long ll;

const int MAXV = 8e6;
int L = 1, R = 1e5, cnt = 1;

struct node
{
    ll val, mark;
    int ls, rs;
} tree[MAXV];

void push_down(int p, int len)
{
    if (len <= 1) return;
    if (!ls(p)) ls(p) = ++cnt;
    if (!rs(p)) rs(p) = ++cnt;
    val(ls(p)) += mark(p) * (len / 2);
    mark(ls(p)) += mark(p);
    val(rs(p)) += mark(p) * (len - len / 2);
    mark(rs(p)) += mark(p);
    mark(p) = 0;
}

ll query(int l, int r, int p = 1, int cl = L, int cr = R)
{
    if (cl >= l && cr <= r) return val(p);
    push_down(p, cr - cl + 1);
    ll mid = (cl + cr - 1) / 2, ans = 0;
    if (mid >= l) ans += query(l, r, ls(p), cl, mid);
    if (mid < r) ans += query(l, r, rs(p), mid + 1, cr);
    return ans;
}

void update(int l, int r, int d, int p = 1, int cl = L, int cr = R)
{
    if (cl >= l && cr <= r) return val(p) += d * (cr - cl + 1), mark(p) += d, void();
    push_down(p, cr - cl + 1);
    int mid = (cl + cr - 1) / 2;
    if (mid >= l) update(l, r, d, ls(p), cl, mid);
    if (mid < r) update(l, r, d, rs(p), mid + 1, cr);
    val(p) = val(ls(p)) + val(rs(p));
}

int main(){
    int temp[] = {4, 1, 4, 6, 7, 7, 5};

    for(int i=0;i<7;i++){
        update(i+1, i+1, temp[i]);
    }
    
    cout<<query(1, 7, 4)<<'\n';
    cout<<query(1, 7, 6)<<'\n';

    return 0;
}