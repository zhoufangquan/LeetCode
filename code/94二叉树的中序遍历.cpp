/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

    void f(TreeNode *root, vector<int> &ans){
        if(root == NULL) return;
        f(root->left, ans);
        ans.push_back(root->val);
        f(root->right, ans);

        return ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {};
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};
// @lc code=end

