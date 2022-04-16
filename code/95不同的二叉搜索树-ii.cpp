/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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

    vector<TreeNode*> f(int l, int r){
        vector<TreeNode*> ans;
        for(int i=l; i<=r; i++){
            TreeNode* p; p = new TreeNode;
            p->val = i;
            p->left = 
            p->right = 

        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};

        return f(1, n);
    }
};
// @lc code=end

