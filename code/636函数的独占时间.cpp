/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    stack<int> S;

    pair<int, pair<int, int>> f(string s){
        pair<int, pair<int, int>> ans;
        string temp = "";
        for(int i=0;i<s.length();i++){
            if(s[i] != ':') temp += s[i];
            else{
                if(temp == "start") ans.second.first = 0;
                else if(temp == "end") ans.second.first = 1;
                else{
                    ans.first = stoi(temp);
                }

                temp = "";
            }
        }
        ans.second.second = stoi(temp);
        return ans;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        int last_end = 0;
        pair<int, pair<int, int>> temp, last_p = f(logs[0]);
        S.push(last_p.first);
        for(int i=1; i<logs.size(); i++){

            temp = f(logs[i]);  // 当前进程

            if(temp.second.first == 0){ // next is start
                if(last_p.second.first == 0) ans[last_p.first] += temp.second.second - last_p.second.second;
                else if(!S.empty()) ans[S.top()] += temp.second.second - last_p.second.second - 1;
                S.push(temp.first);
            }
            else{  // next is end
                if(last_p.second.first == 0) ans[last_p.first] += temp.second.second - last_p.second.second + 1;
                else ans[temp.first] += temp.second.second - last_p.second.second;
                S.pop();
            }

            last_p = f(logs[i]);
        }

        return ans;
    }
};
// @lc code=end

