/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */
#include"HF.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int> > Q;
        Q.push({root, 0});

        while(!Q.empty()){
            auto temp = Q.front(); Q.pop();
            if(ans.size() <= temp.second){
                ans.push_back(INT32_MIN);
            }
            ans[temp.second] = max(ans[temp.second], temp.first->val);
            if(temp.first->left){
                Q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right){
                Q.push({temp.first->right, temp.second+1});
            }
        }

        return ans;
    }
};
// @lc code=end

