/*
剑指 Offer 22. 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
执行用时：4 ms, 在所有 C 提交中击败了62.93% 的用户
内存消耗：5.9 MB, 在所有 C 提交中击败了5.46% 的用户
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//使用一个大小为k的循环指针数组
//依次将链表的指针存放到数组中，满了就覆盖头部，如此循环
//最后数组的head或者tail的循环下一项就是所要的
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int tail = 0;
    struct ListNode **result_array = (struct ListNode **)malloc(k * sizeof(struct ListNode *));
    if (result_array == NULL || head == NULL || k < 1){
        return NULL;
    }

    while (head){
        result_array[tail] = head;
        head = head->next;
        tail = (tail + 1) % k;
    }

    return result_array[tail];
}