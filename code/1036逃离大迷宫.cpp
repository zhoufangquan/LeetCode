/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    vector<vector<bool> > vis;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        map<int, int> row;
        map<int, int> clo;
        vector<int> x,y;
        for(auto &pot : blocked){
            x.push_back(pot[0]);
            y.push_back(pot[1]);
        }
        x.push_back(source[0]);
        x.push_back(target[0]);
        y.push_back(source[1]);
        y.push_back(target[1]);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        auto iter1 = unique(x.begin(), x.end());
        auto iter2 = unique(y.begin(), y.end());
        x.erase(iter1, x.end());
        y.erase(iter2, y.end());

        int r, c;
        int id = 0, pre = -1;
        for(int i:x){
            if(pre+1 == i){
                row[i] = id++;
            }
            else{
                row[i] = id+1;
                id += 2;
            }
            pre = i;
        }
        r = id+1;
        id = 0, pre = -1;
        for(int i:y){
            if(pre+1 == i){
                clo[i] = id++;
            }
            else{
                clo[i] = id+1;
                id += 2;
            }
            pre = i;
        }
        c = id+1;
        if(x[x.size()-1] == 999999) r = row[999999]+1;
        if(y[y.size()-1] == 999999) c = clo[999999]+1;


        vis.resize(r, {});
        for(auto &item: vis)
            item.resize(c, true);

        source[0] = row[source[0]];
        source[1] = clo[source[1]];
        target[0] = row[target[0]];
        target[1] = clo[target[1]];
        for(auto &pot: blocked){
            pot[0] = row[pot[0]];
            pot[1] = clo[pot[1]];
            vis[pot[0]][pot[1]] = false;
        }
        
        bool ans = false;
        queue<pair<int, int>> Q;
        Q.push({source[0], source[1]});
        vis[source[0]][source[1]] = false;
        while(!Q.empty()){
            pair<int, int> temp = Q.front(); Q.pop();
            if(temp.first == target[0] && temp.second == target[1]){
                ans = true;
                break;
            }
            
            for(int i=0;i<4;i++){
                int r0 = temp.first + dr[i];
                int c0 = temp.second + dc[i];

                if(r0<0 || c0<0 || r0>=r || c0>=c) continue;
                if(!vis[r0][c0]) continue;
                Q.push({r0, c0});
                vis[r0][c0] = false;
            }
        }

        return ans;
    }
};
// @lc code=end

int main(){ 
    vector<vector<int> > blocked;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        blocked.push_back({x, y});
    }
    vector<int> source, target;
    string data2, data3;
    cin>>data2>>data3;

    source = stringToIntegerVector(data2);
    target = stringToIntegerVector(data3);

    Solution test;
    bool res = test.isEscapePossible(blocked, source, target);

    return 0;
}

/*
6
0 4
2 4
3 1
3 3
4 0
4 2
[2,2]
[7,3]


[[0,999991],[0,999993],[0,999996],[1,999996],[1,999997],[1,999998],[1,999999]]\n[0,999997]\n[0,2]
7
0 999991
0 999993
0 999996
1 999996
1 999997
1 999998
1 999999
[0,999997]
[0,2]
*/