/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 *
 * [2265] 统计值等于子树平均值的节点数
 */

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
    int ans = 0;

    pair<int, int> postTR(TreeNode* root){
        if (root == NULL) return {0, 0};
        auto L = postTR(root->left);
        auto R = postTR(root->right);

        pair<int, int> N = {L.first+R.first+root->val, L.second+R.second+1};
        
        if(root->val == N.first / N.second) ans ++;

        return N;
    }

    int averageOfSubtree(TreeNode* root) {
        postTR(root);
        return ans;
    }
};
// @lc code=end

