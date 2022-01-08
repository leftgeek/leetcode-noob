/*
https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
剑指 Offer 06. 从尾到头打印链表
[难度：简单]
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

执行结果：
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.9 MB, 在所有 C++ 提交中击败了14.30% 的用户
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        if (head != NULL) {
            recursiveTraverse(result, head);
        }

        return result;
    }

private:
    void recursiveTraverse(vector<int> &result, ListNode *head) {
        if (head->next != NULL) {
            recursiveTraverse(result, head->next);
        }
        result.push_back(head->val);
    }
};