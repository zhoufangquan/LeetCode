/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
#include"HF.h"
// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

    }
};
// @lc code=end

int main(){
    string data1, data2;
    cin>>data1;
    cin>>data2;
    vector<int> nums1 = stringToIntegerVector(data1);
    vector<int> nums2 = stringToIntegerVector(data2);

    Solution test;
    int ans = test.maxUncrossedLines(nums1, nums2);

    cout<<ans;

    return 0;
}
