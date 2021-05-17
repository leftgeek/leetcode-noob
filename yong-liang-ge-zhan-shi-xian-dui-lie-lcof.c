/*
剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof

执行用时：464 ms, 在所有 C 提交中击败了62.28% 的用户
内存消耗：84.2 MB, 在所有 C 提交中击败了6.72% 的用户
TODO:用固定的数组来实现栈而不是用malloc()动态分配，那样效率更高
*/

栈的特点是先进后出，它对外只有弹出-pop()和压入-push()两种操作
pop()必须弹出最近一次压入的数据

队列的特点是先进先出，它对外只有入队-enqueue()和出队-dequeue()两种操作
dequeue()必须移除最先入队的元素

基于这两者的特点，要想用两个栈实现队列的操作。
先考虑连续往队列中加入数据，待完成后，需要dequeue()删除队列的头部。

如果用栈实现，往队列中加入数据的过程，只能不停地往一个栈（栈1）中压入元素。
等到需要从队列中移除头部操作的时候，就把栈1中的元素一个个弹出，然后放到另外一个栈中（栈2）。此时栈2的顺序和栈1刚好相反。于是栈2弹出的元素就是最先入队的元素。

假如此时没有调用移除队列头部的操作，而是调用了入队操作。

此时将新的入队操作一个个压入到栈1中。

等到又调用出队操作时，就把栈2的元素弹出。如果栈2的元素空了。就把栈1的元素一个个弹出，再一个个地压入到栈2中。

也就是说，进行出队操作的时候，是从栈2中弹出元素。
如果栈2中的元素为空，则将栈1中的元素一个个弹出再一个个压入到栈2中。最后再从栈2中弹出元素。
栈1永远负责入队时的压入操作。

//栈元素
struct cstack{
  int val;
  struct cstack *next;
};

typedef struct {
  struct cstack eq_stack;//用来模拟euqneue的栈
  struct cstack dq_stack;//用来模拟dequeue的栈
} CQueue;

//判断栈是否为空
static inline bool cstack_empty(struct cstack *head){
  return (head->next == NULL);
}

//出栈,由调用者来判断栈不为空
//从一个栈向另外一个栈转移数据时，并不需要释放与分配空间
struct cstack *cstack_pop(struct cstack *head){
  struct cstack *stack_top = head->next;
  head->next = stack_top->next;
  
  return stack_top;
}

//入栈,由调用者负责分配新的栈元素空间
void cstack_push(struct cstack *head, struct cstack *new_stack_top){
  new_stack_top->next = head->next;
  head->next = new_stack_top;
}

CQueue* cQueueCreate() {
  CQueue *new_queue = (CQueue *)malloc(sizeof(CQueue));
  if (new_queue){
    (new_queue->eq_stack).next = NULL;
    (new_queue->dq_stack).next = NULL;
  }
  return new_queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
  if (obj){
    struct cstack *new_stack_top = (struct cstack *)malloc(sizeof(struct cstack));
    if (new_stack_top){
      new_stack_top->val = value;
      cstack_push(&obj->eq_stack, new_stack_top);
    }
  }
}

int cQueueDeleteHead(CQueue* obj) {
  int result = -1;
  if (obj){
    //如果dq_stack不为空，就直接弹出它的head就是队列的head
    //否则要将eq_stack中的所有元素弹出，并依次push到dq_stack中
    struct cstack *stack_top;
    if (cstack_empty(&obj->dq_stack)
      && !cstack_empty(&obj->eq_stack)){
      do {
        stack_top = cstack_pop(&obj->eq_stack);
        cstack_push(&obj->dq_stack, stack_top);
      } while (!cstack_empty(&obj->eq_stack));
    }
    if (!cstack_empty(&obj->dq_stack)){
      stack_top = cstack_pop(&obj->dq_stack);
      result = stack_top->val;
      free(stack_top);
    }
  }

  return result;
}

void cQueueFree(CQueue* obj) {
  if (obj){
    struct cstack *stack_top;
    while (!cstack_empty(&obj->dq_stack)){
      stack_top = cstack_pop(&obj->dq_stack);
      free(stack_top);
    }
    while (!cstack_empty(&obj->eq_stack)){
      stack_top = cstack_pop(&obj->eq_stack);
      free(stack_top);
    }

    free(obj);
  }
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/