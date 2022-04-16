/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void f(TreeNode *root){
        if(root == NULL) return;
        f(root->left);
        f(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return ans;
    }
};
// @lc code=end

int main(){
    string data;
    cin>>data;
    TreeNode *root = get_tree(data);
    Solution test;
    vector<int> res = test.postorderTraversal(root);
    for(auto &item: res){
        cout<<item<<' ';
    }
    cout<<'\n';

    return 0;
}