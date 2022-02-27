/*
141. 环形链表
[难度：简单]
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle

执行用时：8 ms, 在所有 C++ 提交中击败了93.30% 的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了59.53% 的用户
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
    bool hasCycle(ListNode *head) {
        bool result = false;

        while (head != nullptr) {
            //-100000 <= Node.val <= 100000
            //利用这一点，将已经遍历过的节点值标记为该范围之外的值（100001）
            if (head->val == 100001) {
                result = true;
                break;
            } else {
                head->val = 100001;
                head = head->next;
            }
        }

        return result; 
    }
};