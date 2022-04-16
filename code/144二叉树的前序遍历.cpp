/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
        if(root == NULL) return ;
        ans.push_back(root->val);
        f(root->left);
        f(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
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
    vector<int> res = test.preorderTraversal(root);
    for(auto &item: res){
        cout<<item<<' ';
    }
    cout<<'\n';

    return 0;
}
