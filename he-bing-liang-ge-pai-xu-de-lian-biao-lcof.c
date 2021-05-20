/*
剑指 Offer 25. 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
执行用时：16 ms, 在所有 C 提交中击败了44.38% 的用户
内存消耗：7.2 MB, 在所有 C 提交中击败了33.83% 的用户
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head;
    struct ListNode *node;

    if (l1 == NULL){
        head = l2;
    } else if (l2 == NULL){
        head = l1;
    } else {
		//处理链表头节点
        if (l1->val <= l2->val){
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        node = head;
		//处理两个链表，依次选择值小的
        while (l1 && l2){
            if (l1->val <= l2->val){
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
		//处理剩余链表节点
        if (l1){
            node->next = l1;
        } else {
            node->next = l2;
        }
    }

    return head;
}