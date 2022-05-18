#include<bits/stdc++.h>

using namespace std;
int n;
int par[100005];
char C[100005];
pair<int, int> BW[100005];

int solve1(){
    int ans = 0;
    for(int i=n;i>=1;i--){
        if(C[i-1] == 'B') BW[i].first ++;
        if(C[i-1] == 'W') BW[i].second ++;
        if (BW[i].second == BW[i].first) ans ++;
        BW[par[i]].first += BW[i].first;
        BW[par[i]].second += BW[i].second;
    }
    return ans;
}


int main(){
    int t; cin>>t;
    par[1] = -1;
    while(t -- ){
        scanf("%d", &n);
        BW[1] = {0, 0};
        for(int i=2; i<=n;i++){
            scanf("%d", par+i);
            BW[i] = {0, 0};
        }
        scanf("%s", C);
        cout<<solve1()<<'\n';
    }
    return 0;
}