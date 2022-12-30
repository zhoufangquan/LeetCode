/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int temp;
        for(int i=0;i<asteroids.size();i++){
            if(ans.size() == 0 ||asteroids[i] > 0) ans.push_back(asteroids[i]);
            else{
                while(ans.size() > 0){
                    temp = ans[ans.size()-1];
                    if(temp<0) break;
                    ans.pop_back();
                    if(temp + asteroids[i] == 0) break;
                    else if(temp + asteroids[i] > 0){
                        ans.push_back(temp);
                        break;
                    }
                }
                if(temp + asteroids[i] < 0) ans.push_back(asteroids[i]);
            }
        }

        return ans;

    }
};
// @lc code=end

