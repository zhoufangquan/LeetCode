/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 0});
        while (!Q.empty())
        {
            pair<TreeNode *, int> temp = Q.front(); Q.pop();
            if(temp.second+1 > ans.size()){
                ans.push_back({});
            }
            ans[temp.second].push_back(temp.first->val);
            
            if(temp.first->left) Q.push({temp.first->left, temp.second+1});
            if(temp.first->right) Q.push({temp.first->right, temp.second+1});
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
    vector<vector<int> > ans = test.levelOrder(root);
    for(auto &item: ans){
        for(auto &i: item)
            cout<<i<<' ';
        cout<<'\n';
    }
    cout<<'\n';
    return 0;
}