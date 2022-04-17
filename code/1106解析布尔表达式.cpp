/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    bool opt(char op, string vars){
        if(op == '!'){
            if(vars[0] == 'f') return true;
            else return false;
        }
        else if(op == '|'){
            for(int i=0;i<vars.length();i++){
                if(vars[i] == 't') return true;
            }
            return false;
        }
        else{
            for(int i=0;i<vars.length();i++){
                if(vars[i] == 'f') return false;
            }
            return true;
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char> S;

        for(int i=0;i<expression.length();i++){
            if(expression[i] == ')'){
                string vars = "";
                char op;
                while(!S.empty()){
                    char v = S.top(); S.pop();
                    if(v == '('){
                        op = S.top(); S.pop();
                        break;
                    }
                    vars += v;
                }
                bool temp = opt(op, vars);
                if(temp) S.push('t');
                else S.push('f');
            }
            else{
                if(expression[i] == ',') continue;
                S.push(expression[i]);
            }
        }
        if(S.top() == 'f') return false;
        else return true;
    }
};
// @lc code=end

int main(){
    string data;
    cin>>data;
    Solution test;
    bool ans = test.parseBoolExpr(data);
    cout<<ans;
    return 0;
}
