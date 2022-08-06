/*
 * @lc app=leetcode.cn id=1451 lang=cpp
 *
 * [1451] 重新排列句子中的单词
 */
#include"HF.h"
// @lc code=start
bool cmp(string &a, string &b){
    return a.length() < b.length();
}

class Solution {
public:

    vector<string> split(string s){
        vector<string> ans;
        string temp="";

        for(int i=0;i<s.length(); i++){
            if(s[i] != ' ') temp += s[i];
            else{
                ans.push_back(temp);
                temp = "";
            }
        }
        ans.push_back(temp);
        return ans;
    }

    string join(vector<string> ss){
        string ans = ss[0];
        for(int i=1;i<ss.size();i++){
            ans += " ";
            ans += ss[i];
        }
        return ans;
    }

    string arrangeWords(string text) {
        vector<string> ss;
        text[0] = text[0] + 32;
        ss = split(text);

        sort(ss.begin(), ss.end(), cmp);

        return join(ss);
    }
};
// @lc code=end

int main(){
    Solution test;
    string IN;
    cin>>IN;
    cout<<test.arrangeWords(IN);
}