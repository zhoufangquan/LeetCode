/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* pre= new TreeNode(INT32_MIN);
    bool flag = 0;
    bool f(TreeNode* root){
        if(flag) return flag;
        if(root == NULL) return false;
        f(root->left);
        if(pre->val < root->val) pre = root;
        else{
            swap(pre->val , root->val);
            flag = true;
            return true;
        }

        f(root->right);
        return true;
    }
    void recoverTree(TreeNode* root) {


        while(f(root)) flag = false;
    }

private:
};
// @lc code=end

