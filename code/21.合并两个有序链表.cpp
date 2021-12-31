/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include"HF.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans, *q;
        ans = new ListNode;
        ans->next = NULL;
        q = ans;
        while (list1 && list2)
        {
            if(list1->val <= list2->val){
                ans->next = list1;
                list1 = list1->next;
            }
            else{
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }
        if(list1) ans->next = list1;
        if(list2) ans->next = list2;

        return q->next;
    }
};
// @lc code=end
