/*
206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
执行用时：4 ms, 在所有 C 提交中击败了89.12% 的用户
内存消耗：6.1 MB, 在所有 C 提交中击败了94.92% 的用户
https://leetcode-cn.com/problems/reverse-linked-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (!head || !head->next){
        return head;
    }
    struct ListNode *curr_node = head->next;
    struct ListNode *next_node;
    head->next = NULL;
    while (curr_node != NULL){
        next_node = curr_node->next;
        curr_node->next = head;
        head = curr_node;
        curr_node = next_node;
    }
    return head;
}