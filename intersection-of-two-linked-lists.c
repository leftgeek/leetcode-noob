/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
执行用时：40 ms, 在所有 C 提交中击败了90.41% 的用户
内存消耗：13.5 MB, 在所有 C 提交中击败了90.34% 的用户
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//基本思想：使用两个指针，分别遍历两个链表，当一个链表遍历完了之后就遍历另外一个链表
//最后当两个指针相等或者为空时就是目标节点
//原理是假定两个链表的长度分别为m和n
//则一个指针先遍历完m，再遍历n，另外一个指针先遍历n，再遍历m
//那么如果两个链表有相交的节点，则两个指针总会在某一时刻遍历到同一个节点
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *intersected_node = NULL;
    struct ListNode *node_a, *node_b;
    
    if (headA && headB){
        node_a = headA;
        node_b = headB;

        while (1){
            if (node_a == node_b){
                break;
            }
            node_a = node_a->next;
            node_b = node_b->next;
            if (node_a == node_b){
                break;
            }
            if (!node_a){
                node_a = headB;
            }
            if (!node_b){
                node_b = headA;
            }
        }
        intersected_node = node_a;
    }
    return intersected_node;
}