#include<bits/stdc++.h>

using namespace std;
int c_[200005], r_[200005];
bool cf[100005], rf[100005];

void bulid_T(int ro, int s, int e){
    if(s>e) return;
    if (s == e){
        c_[ro] = 0;
        r_[ro] = 0;
        return ;
    }
    bulid_T(2*ro+1, s, s+(e-s)/2);
    bulid_T(2*ro+2, s+(e-s)/2+1, e);
    c_[ro] = c_[2*ro+1] + c_[2*ro+2];
    r_[ro] = r_[2*ro+1] + r_[2*ro+2];
}

void modifyN(int ro, int s, int e, int x, int val, bool cr){
    if(s>e) return;
    
    if(s<=x && x<=e && cr == 0) r_[ro] += val;
    if(s<=x && x<=e && cr == 1) c_[ro] += val;
    if(s<e) {
        int mid = s+(e-s)/2;
        if(s<=x && x<=mid) modifyN(2*ro+1, s, mid, x, val, cr);
        if(mid<x && x<=e) modifyN(2*ro+2, mid+1, e, x, val, cr);
    }
}

int query(int ro, int s, int e, int x, int y, bool cr){
    int ans = 0;
    if(s>e) return ans;
    if(x<=s && e<=y && cr==0){
        ans += r_[ro];
        return ans;
    } 
    if(x<=s && e<=y && cr==1){
        ans += c_[ro];
        return ans;
    } 
    if(s<e){
        int mid = s+(e-s)/2;
        // [s, mid]
        if(y>=s && mid>=x) ans += query(2*ro+1, s, mid, x, y, cr);
        // (mid, e]
        if(y>mid && e>=x) ans += query(2*ro+2, mid+1, e, x, y, cr);
    }
    return ans;
}

void f(){
    for(int i=0;i<15;i++)
        cout<<c_[i]<<' ';
    cout<<'\n';
}

int main(){
    int n, q;
    cin>>n>>q;
    bulid_T(0, 1, n);
    f();
    memset(rf, false, sizeof rf);
    memset(cf, false, sizeof cf);
    while(q--){
        int t, x1, y1, x2, y2;
        scanf("%d", &t);
        if(t == 1){
            scanf("%d%d", &x1, &y1);
            /// todo  增加节点
            if(!rf[x1]) modifyN(0, 1, n, x1, 1, 0);
            if(!cf[y1]) modifyN(0, 1, n, y1, 1, 1);
            rf[x1] = true;
            cf[y1] = true;
        }
        else if(t == 2){
            scanf("%d%d", &x1, &y1);
            /// todo  删除节点
            if(rf[x1]) modifyN(0, 1, n, x1, -1, 0);
            if(cf[y1]) modifyN(0, 1, n, y1, -1, 1);  
            rf[x1] = false;
            cf[y1] = false;
        }
        else{
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            /// todo  两个区间查询
            int res0 = query(0, 1, n, x1, x2, 0);
            int res1 = query(0, 1, n, y1, y2, 1);
            cout<<res0<<' '<<res1<<'\n';
            if(res0 == (x2-x1+1) || res1 == (y2-y1+1)){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }

    return 0;
}

/*
8 10
1 2 4
3 6 2 7 2
1 3 2
3 6 2 7 2
1 4 3
3 2 6 4 8
2 4 3
3 2 6 4 8
1 4 8
3 2 6 4 8


8 5
1 2 4
1 3 2
1 4 3
2 4 3
1 4 8

*/