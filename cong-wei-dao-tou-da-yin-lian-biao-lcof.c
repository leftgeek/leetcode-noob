/*
剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
执行用时：12 ms, 在所有 C 提交中击败了57.36% 的用户
内存消耗：7.3 MB, 在所有 C 提交中击败了24.78% 的用户
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void traverse_recursive(struct ListNode *head, int *result_array,
    int size, int current_index){
  if (head->next){
    traverse_recursive(head->next, result_array, size, current_index + 1);
  }
  result_array[size - current_index - 1] = head->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
  int *result_array = NULL;
  int i = 0;
  struct ListNode *nodep = head;
  while (nodep != NULL){
    i++;
    nodep = nodep->next;
  }
  *returnSize = i;
  if (i){
    result_array = (int *)malloc(i * sizeof(int));
    traverse_recursive(head, result_array, i, 0);
  }
  return result_array;
}