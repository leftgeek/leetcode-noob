/*
142. 环形链表 II
[难度：中等]
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。
进阶：你是否可以使用 O(1) 空间解决此题？【当前采用了hash表，所以空间并不是最优】
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii

执行用时：4 ms, 在所有 C++ 提交中击败了98.11% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了6.31% 的用户
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
    ListNode *detectCycle(ListNode *head) {
        std::unordered_map<ListNode *, ListNode *> known_nodes;
        ListNode *curr = nullptr;

        while (head != nullptr) {
            known_nodes.insert(pair(head, head));
            std::unordered_map<ListNode *, ListNode *>::iterator hi = known_nodes.find(head->next);
            if (hi != known_nodes.end()) {
                curr = hi->second;
                break;
            } else {
                head = head->next;
            }
        } 

        return curr; 
    }
};