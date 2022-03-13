/*
143. 重排链表
[难度：中等]
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln

请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list

执行用时：32 ms, 在所有 C++ 提交中击败了84.96% 的用户
内存消耗：17.2 MB, 在所有 C++ 提交中击败了98.11% 的用户
*/

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
 //先找到中间节点
 //然后反转后半部分的链表
 //最后对前半部分和反转后的后半部分链表进行交叉归并
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((head != nullptr) && (head->next != nullptr)) {
            ListNode *mid_node = head;
            ListNode *tail_node = head;

            while (tail_node != nullptr) {
                //mid_node每次向后移动一个节点
                mid_node = mid_node->next;
                //tail_node每次向后移动两个节点
                tail_node = tail_node->next;
                if (tail_node != nullptr) {
                    tail_node = tail_node->next;
                }
            }
            //反转从mid_node开始的部分链表,mid_node会成为反转链表的末尾节点
            ListNode *reverse_head = mid_node;
            ListNode *cur_node = reverse_head->next;
            while (cur_node != nullptr) {
                ListNode *next_node = cur_node->next;
                mid_node->next = next_node;
                cur_node->next = reverse_head;
                reverse_head = cur_node;
                cur_node = next_node;
            }
            //交叉合并head和reverse_head开头的链表
            ListNode *cur_node1 = head;
            ListNode *cur_node2 = reverse_head;
            cur_node = cur_node1;
            while ((cur_node1 != mid_node)) {
                //轮流从两个链表中取出一个节点，拼接成新的链表
                if (cur_node == cur_node1) {
                    ListNode *next_node1 = cur_node1->next;
                    cur_node->next = cur_node2;
                    cur_node1 = next_node1;
                } else {
                    ListNode *next_node2 = cur_node2->next;
                    cur_node->next = cur_node1;
                    cur_node2 = next_node2;
                }
                cur_node = cur_node->next;
            }
        }
    }
};