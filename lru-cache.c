/*
146. LRU 缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。

实现 LRUCache 类：

    LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
    int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
    void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache

执行用时：92 ms, 在所有 C 提交中击败了99.15% 的用户
内存消耗：24.6 MB, 在所有 C 提交中击败了67.38% 的用户
*/

#define MAX_VAL 3001
//双向循环链表
struct list_node {
    int key;
    int val;
    struct list_node *next;
    struct list_node *prev;
};

typedef struct {
    int size;
    int capacity;
    struct list_node lru_head;
    //每一个hash桶指向一个节点
    struct list_node *buckets[MAX_VAL];
} LRUCache;

void list_add_head(struct list_node *head, struct list_node *node){
    struct list_node *next = head->next;
    head->next = node;
    node->prev = head;
    node->next = next;
    if (next){
        next->prev = node;
    }
}

void list_del_node(struct list_node *head, struct list_node *node){
    struct list_node *prev = node->prev;
    struct list_node *next = node->next;
    prev->next = next;
    if (next){
        next->prev = prev;
    }
}

struct list_node *list_del_tail(struct list_node *head){
    struct list_node *tail_node = head->prev;
    struct list_node *prev = tail_node->prev;
    //head is tail_node->next node
    head->prev = prev;
    prev->next = head;

    return tail_node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *lru = (LRUCache *)malloc(sizeof(LRUCache));
    if (lru){
        lru->capacity = capacity;
        lru->size = 0;
        lru->lru_head.next = &(lru->lru_head);
        lru->lru_head.prev = &(lru->lru_head);
        memset(lru->buckets, 0, MAX_VAL * sizeof(struct list_node *));
    }
    return lru;
}

int lRUCacheGet(LRUCache* obj, int key) {
    struct list_node *target_node = obj->buckets[key];
    int value = -1;

    if (target_node != NULL){
        //将target_node移到lru链表的头部
        list_del_node(&(obj->lru_head), target_node);
        list_add_head(&(obj->lru_head), target_node);
        value = target_node->val;
    }

    return value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    struct list_node *target_node = obj->buckets[key];
    if (target_node != NULL){
        //更新节点值并移动到lru链表头部
        target_node->val = value;
        list_del_node(&(obj->lru_head), target_node);
    } else {
        if (obj->size < obj->capacity){
            target_node = (struct list_node *)malloc(sizeof(struct list_node));
            obj->size++;
        } else {
            //需要释放最久未使用的节点，即lru链表末尾节点
            //直接将该末尾节点用作待添加的新节点  
            target_node = list_del_tail(&(obj->lru_head));
            obj->buckets[target_node->key] = NULL;
        }
        target_node->key = key;
        target_node->val = value;
        obj->buckets[key] = target_node;
    }
    //将target_node添加到lru链表的头部
    list_add_head(&(obj->lru_head), target_node);
}

void lRUCacheFree(LRUCache* obj) {
    struct list_node *node;
    struct list_node *next;
    for (node = obj->lru_head.next; node != &(obj->lru_head);){
        next = node->next;
        free(node);
        node = next;
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/