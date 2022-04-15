/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long long pre = INT64_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool l = isValidBST(root->left);
        if(pre<root->val){
            pre = root->val;
        }
        else return false;
        bool r = isValidBST(root->right);
        return l && r;
    }
};
// @lc code=end

