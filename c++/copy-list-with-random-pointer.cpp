/*
138. 复制带随机指针的链表
[难度：中等]
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer

执行用时：8 ms, 在所有 C++ 提交中击败了76.61% 的用户
内存消耗：11 MB, 在所有 C++ 提交中击败了82.02% 的用户
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//此题目的最根本目的，是希望能够通过原始链表节点的random指向关系，立即定位到新链表的random指向关系
//为此最好就是让原始链表的节点直接指向新链表的相应节点
//因此直接先拷贝原有链表的所有random指针，并让原先的每个链表的节点指向新分配的链表的对应节点
//目的是遍历原链表的每个节点的random时，直接找到与之对应的新分配链表的节点，从而快速更新新链表的random指针
//如果原始链表的节点为a和b，a->next = b，且a->random = b
//那么构造新的链表节点为A和B, A->next = B，并且在构建每个新节点时，
//先让新链表的每个节点的random指针指向原始链表的相应节点，即A->random = a, B->random = b
//并让原链表的每个节点的next指针指向新链表的相应节点，即a->next = A, b->next = B
//这样，我们最后再构造新链表的random指针时，直接再遍历一次新构造的链表
//利用旧链表的next指向关系还原新链表的random指向关系
//利用第三个链表的random指向关系还原原始链表的next指向关系

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *new_head = NULL;//新链表
        Node *new_current;
        Node *old_current = head;
        Node *extra_head = NULL;//用于还原原始链表next指向关系的链表
        Node *extra_current;
        
        while (old_current != NULL) {
            //构造新链表
            if (new_head == NULL) {
                new_head = new Node(old_current->val);
                new_current = new_head;

                extra_head = new Node(0);
                extra_current = extra_head;
            } else {
                new_current->next = new Node(old_current->val);
                new_current = new_current->next;

                extra_current->next = new Node(0);
                extra_current = extra_current->next;
            }
            //先让新链表节点的random指针，指向原始链表的对应节点
            new_current->random = old_current;

            //记录原始链表的next指向关系
            extra_current->random = old_current;

            //临时修改原链表节点的next指针，指向新链表的对应节点
            Node *old_next = old_current->next;
            old_current->next = new_current;
            old_current = old_next;
        }

        //遍历新链表，根据每个节点的random指针找到对应的原链表指针，再拷贝原链表的random指向关系
        //FIXME:不能用新链表的random指向关系还原原始链表的next指向关系，而要借助第三方链表的原因：
        //如果原始链表的一个节点没有被random指到，那么它的next指针就不会被还原
        //而实际上，如果一个原始链表的节点没有被random指到，那么它的next指针就不需要被修改！
        //另外，原始链表的一个节点可能被多个random指到，这时它的next指针就会需要使用多次
        //因此不急着还原它的next指针，而是等到最后集中还原
        //目前一个简单的解决办法是再新建一份链表，它的每个random元素依次记录着原始链表的每个节点
        //等新链表的random指针复制完毕后，再通过它来还原旧链表的next关系
        new_current = new_head;
        while (new_current != NULL) {
            //从新链表的random关系中还原原始链表的next指向关系
            old_current = new_current->random;
 
            //FIXME:由于可能出现环，因此会出现空指针情况
            //获取原始链表的random指向关系
            Node *old_random = old_current->random;
            //再通过原始链表的random节点找到对应的新链表节点,这个节点就是新链表的random指针值
            Node *new_random = NULL;
            //单独处理环路节点
            if (old_random == old_current) {
                new_random = new_current;
            } else if (old_random != NULL) {
                new_random = old_random->next;
            }
            new_current->random = new_random;
            
            new_current = new_current->next;
        }

        //集中还原旧链表的next指向关系
        if (extra_head) {
            old_current = head;
            extra_current = extra_head->next;
            while (extra_current != NULL) {
                old_current->next = extra_current->random;
                old_current = old_current->next;
                extra_current = extra_current->next;
            }
            old_current->next = NULL;
        }

        return new_head;
    }
};