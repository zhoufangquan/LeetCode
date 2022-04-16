/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> tt;
        if(root == NULL) return ans;
        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 0});
        while (!Q.empty())
        {
            pair<TreeNode *, int> temp = Q.front(); Q.pop();
            if(temp.second+1 > tt.size()){
                tt.push_back({});
            }
            tt[temp.second].push_back(temp.first->val);
            
            if(temp.first->left) Q.push({temp.first->left, temp.second+1});
            if(temp.first->right) Q.push({temp.first->right, temp.second+1});
        }
        for(auto &item: tt){
            ans.push_back(item[item.size()-1]);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    string data;
    cin>>data;
    TreeNode *root = get_tree(data);
    Solution test;
    vector<int> ans = test.rightSideView(root);
    for(auto &item: ans){
        cout<<item<<' ';
    }
    cout<<'\n';
    return 0;
}