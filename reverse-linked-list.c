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

//solution 1:
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

//solution 2:
struct ListNode* reverseList_recursive(struct ListNode* head){
    if (!head || !head->next){
        return head;
    }
    //假定head->next到tail的已经被反转
    //返回末尾的tail
    struct ListNode *tail = reverseList_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return tail;
}
